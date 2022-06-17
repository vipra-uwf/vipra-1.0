import https from 'https';
import express from 'express';
import cors from 'cors';
import { Endpoint } from './Types/Endpoint';
import { cbErrorRespond, cbResultRespond } from './Types/Responses';
import { ResultStore } from './Types/ResultStore';
import { Service } from './Types/Service';


export class CBServer{

    private httpsServer     : https.Server;
    private express         : express.Application;
    private port            : number;
    private rootEndpoint    : Endpoint;
    private resultStores    : Map<string, ResultStore>;
    private baseURL         : string;

    constructor(
        options:{
            port : number,
            baseURL : string,
            httpsCredentials : {
                key: Buffer,
                cert: Buffer,
                passphrase?: string,
            }
        }
    ){
        this.port = options.port;
        this.baseURL = options.baseURL;
        this.resultStores = new Map();
        this.makeRootEndpoint();
        this.setupServer(options.httpsCredentials);
    }

    public start(){
        this.httpsServer.listen(this.port, ()=>{
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

    public getResultStore(name : string){
        return this.resultStores.get(name);
    }

    private makeRootEndpoint() : void{
        this.rootEndpoint = new Endpoint('services');
        this.rootEndpoint.setHref(this.baseURL.concat('services'));
    }

    private setupServer(credentials : {key : Buffer, cert : Buffer, passphrase? : string}){
        this.express = express();
        this.express.use(cors());
        this.express.use(express.urlencoded({extended: true}));
        this.express.use(express.json());
        this.express.use('/data', (req : express.Request, res : express.Response)=>{
            this.respondResult(req, res);
        });
        this.express.use('*', (req : express.Request, res : express.Response)=>{
            this.routeRequest(req, res);
        });

        this.httpsServer = https.createServer(credentials, this.express);
    }

    private fillRouteWithEmpty(route : string){
        const r = route.split('/');
        for(let i = 0; i < r.length; i++) {
            if(r[i] === ''){
                return;
            }
            if(!this.getEndpoint(r.slice(0, i))){
                let ep = this.getEndpoint(r.slice(i, i+1));
                ep.addEndpoint(new Endpoint(r[i+1]));
            }
        }
    }

    public addService(options : {
        route : string,
        service : Service
    }){
        this.fillRouteWithEmpty(options.route);
        this.addResultStore(options.service.getResultStore());
        const ep = this.getEndpoint(options.route.split('/'));
        ep.setService(options.service);
        ep.getService().setResultStore(options.service.getResultStore());
        options.service.setHref(this.baseURL.concat('/', options.route));
    }

    private async respondResult(req : express.Request, res : express.Response) : Promise<void>{
        const path : string[] = req.url.split('/');
        const resultStore = this.resultStores.get(path[1]);
        if(resultStore){
            resultStore.handleRequest(path, res);
            return;
        }else{
            cbErrorRespond('No Result Store at path: ${path}', res);
            return;
        }
    }

    private addResultStore(resultStore : ResultStore){
        if(this.getResultStore(resultStore.getName())){
            return;
        }
        const href = this.baseURL.concat('data/', resultStore.getName(), '/');
        resultStore.setHref(href);
        this.resultStores.set(resultStore.getName(), resultStore);
    }
}