import express from 'express';

import { cbErrorRespond, cbLinksRespond } from "./Responses";
import { Service } from "./Service";
import { Link } from "./Types";



export class Endpoint{

    private name        : string;
    private href        : string;
    private links       : Map<string, Endpoint>;

    private service     : Service;


    constructor(name : string, baseHref : string){
        if(name === '' || name === null || name === undefined){
            throw new Error(`Endpoint names cannot be empty`);
        }
        this.name = name;
        this.href = `${baseHref}${name}/`;
        this.links = new Map();
    }

    public treeTraverse(route : string[]) : Endpoint{
        let popped : string = route.shift();
        while(popped === ""){
            popped = route.shift();
        }
        if(popped){
            if(popped === '' || popped.charAt(0) === '?'){
                return this;
            }
            const next = this.links.get(popped);
            if(next){
                return next.treeTraverse(route);
            }else{
                return null;
            }
        }else{
            return this;
        }
    }
    public handleRequest(request : express.Request, response : express.Response){
        if(!this.service){
            cbLinksRespond(this.getLinks(), response);
        }else{
            this.service.handleRequest(request, response)
            .catch((error)=>{
                cbErrorRespond(`Unknown Error`, response);
            });
        }
    }
    public addEndpoint(endpoint : Endpoint){
        if(this.links.has(endpoint.name)){
            throw new Error(`Endpoint already has link to: ${endpoint.name}`);
        }
        endpoint.setHref(`${this.href}${endpoint.name}`);
        this.links.set(endpoint.name, endpoint);
    }

    public getEndpoint(name : string) : Endpoint{
        if(this.links.has(name)){
            return this.links.get(name);
        }else{
            return null;
        }
    }

    public setService(service : Service){
        this.service = service;
    }
    public getService() : Service{
        return this.service;
    }

    public getLinks() : Link[]{
        const links : Link[] = [];
        for(const [name, endpoint] of this.links.entries()){
            links.push({
                name,
                href: endpoint.getHref()
            });
        }
        return links;
    }

    public setHref(href : string){
        this.href = href;
    }

    public getHref() : string{
        return this.href;
    }

    public getName() : string{
        return this.name;
    }
}