import express from 'express';

import { Endpoint } from './Endpoint';
import { cbErrorRespond } from './Responses';
import { ResultStore } from './ResultStore';
import { Service } from './Service';


// TODO add logging -RG
// TODO make sure when user enters route for new service/endpoint that it is changed to the proper format -RG

export class CBServer{
    private endpoints       : Map<string, Endpoint>;
    private resultStores    : Map<string, ResultStore>;
    private baseURL         : string;

    constructor(baseURL : string){
        this.baseURL = baseURL;
        this.resultStores = new Map();
        this.endpoints = new Map();
    }

    public handleChainBuilderRequest(request : express.Request, response: express.Response){
        const route : string[] = request.originalUrl.split('/');
        while(route[0] === ''){
            route.shift();
        }

        if(route[0] === 'data'){
            this.respondResult(request, response);
        }else{
            const endpoint : Endpoint = this.getEndpoint(route);

            if(endpoint){
                endpoint.handleRequest(request, response);
            }else{
                cbErrorRespond(`No Endpoint at: ${request.url}`, response);
            }
        }

    }

    public getEndpoint(route : string[]) : Endpoint{
        let popped : string = "";
        while(popped === ""){
            popped = route.shift();
        }
        if(popped){
            if(this.endpoints.has(popped)){
                return this.endpoints.get(popped).treeTraverse(route);
            }else{
                return null;
            }
        }else{
            return null;
        }
    }

    public hasRoute(route : string) : boolean{
        return this.getEndpoint(route.split('/')) !== null;
    }

    public getResultStore(name : string){
        return this.resultStores.get(name);
    }

    public addRoute(route : string){
        const r : string[] = route.split('/');
        let curr : string = r.shift();

        while(curr === ""){
            curr = r.shift();
        }

        if(curr === 'data'){
            throw new Error('Routes that start with /data/ are reserved');
        }

        if(!this.endpoints.has(curr)){
            this.endpoints.set(curr, new Endpoint(curr, this.baseURL));
        }

        let currEndpoint : Endpoint = this.endpoints.get(curr);
        r.forEach((name : string) =>{
            if(name !== ""){
                let ep = currEndpoint.getEndpoint(name);
                if(!ep){
                    ep = new Endpoint(name, currEndpoint.getHref());
                    currEndpoint.addEndpoint(ep);
                    currEndpoint = ep;
                }else{
                    currEndpoint = ep;
                }
            }
        });
    }

    public addService(options : {
        route : string;
        service : Service;
    }){
        this.addRoute(options.route);
        this.addResultStore(options.service.getResultStore());
        const ep : Endpoint = this.getEndpoint(options.route.split('/'));
        ep.setService(options.service);
        ep.getService().setResultStore(options.service.getResultStore());
        options.service.setHref(`${this.baseURL}${options.route}/`);
    }

    private respondResult(req : express.Request, res : express.Response) : void{
        const path : string[] = req.url.split('/');
        const resultStore = this.resultStores.get(path[1]);
        if(resultStore){
            resultStore.handleRequest(path, res);
            return;
        }else{
            cbErrorRespond(`No Result Store at path: ${req.url}`, res);
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