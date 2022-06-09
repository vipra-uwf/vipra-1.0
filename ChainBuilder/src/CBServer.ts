import express from 'express';
import { Endpoint } from './Types/Endpoint';
import { cbErrorRespond } from './Types/Responses';


export class CBServer{

    private server          : express.Application;
    private port            : number;
    private rootEndpoint    : Endpoint;
    private baseURL         : string;

    constructor(port : number, baseURL : string, root : string){
        this.port = port;
        this.baseURL = baseURL;
        this.makeRootEndpoint(root);
        this.setupServer();
    }

    public start(){
        this.server.listen(this.port, ()=>{
            console.log(`Listening on Port: ${this.port}`);
        });
    }

    public routeRequest(request : express.Request, response: express.Response){
        const route : string[] = request.originalUrl.split('/');
        let endpoint : Endpoint;
        route.shift();
        if(route.shift() === this.rootEndpoint.getName()){
            endpoint = this.rootEndpoint.treeTraverse(route);
        }

        if(endpoint){
            endpoint.handleRequest(request, response);
        }else{
            cbErrorRespond(`No Endpoint at: ${request.url}`, response);
        }
    }

    public getEndpoint(route : string[]){
        const popped = route.shift();
        if(popped === this.rootEndpoint.getName()){
            return this.rootEndpoint.treeTraverse(route);
        }else{
            return null;
        }
    }

    private makeRootEndpoint(root : string) : void{
        this.rootEndpoint = new Endpoint(root);
        this.rootEndpoint.setHref(this.baseURL.concat(`/${root}`));
    }

    private setupServer(){
        this.server = express();
        this.server.use(express.urlencoded({extended: true}));
        this.server.use(express.json());
        this.server.use('*', (req : express.Request, res : express.Response)=>{
            this.routeRequest(req, res);
        });
    }
}