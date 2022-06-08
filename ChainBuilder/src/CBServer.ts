import { createServer, IncomingMessage, Server, ServerResponse } from 'http';
import { CBEndpoint } from './CBEndpoint';
import { cbErrorRespond } from './Types/CBResponse';


export class CBServer{

    private server          : Server;
    private port            : number;
    private rootEndpoint    : CBEndpoint;
    private baseURL         : string;

    constructor(port : number, baseURL : string, root : string){
        this.port = port;
        this.baseURL = baseURL;
        this.makeRootEndpoint(root);
        this.server = createServer((request : IncomingMessage, response : ServerResponse)=>{
            this.routeRequest(request, response);
        });
    }

    public start(){
        this.server.listen(this.port, ()=>{
            console.log(`Listening on Port: ${this.port}`);
        });
    }

    public routeRequest(request : IncomingMessage, response: ServerResponse){
        const route : string[] = request.url.split('/');
        let endpoint : CBEndpoint;
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
        this.rootEndpoint = new CBEndpoint(root);
        this.rootEndpoint.setHref(this.baseURL.concat(`/${root}`));
    }
}