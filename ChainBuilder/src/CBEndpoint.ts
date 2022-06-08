import { IncomingMessage, ServerResponse } from "http";
import { CBLink } from "./Types/CBLink";
import { cbLinksRespond } from "./Types/CBResponse";
import { CBService } from "./Types/CBService";


export class CBEndpoint{

    private name        : string;
    private href        : string;
    private links       : Map<string, CBEndpoint>;
    private service     : CBService;


    constructor(name : string){
        if(name === ''){
            throw new Error(`Endpoint names cannot be empty`);
        }
        this.name = name;
        this.href = '';
        this.links = new Map();
    }

    public treeTraverse(route : string[]) : CBEndpoint{
        const popped = route.shift();

        if(popped){
            if(popped === ''){
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

    public handleRequest(request : IncomingMessage, response : ServerResponse){
        if(!this.service){
            cbLinksRespond(this.getLinks(), response);
        }else{
            this.service.handleRequest(request, response);
        }
    }

    public addEndpoint(endpoint : CBEndpoint){
        if(this.links.has(endpoint.name)){
            throw new Error(`Endpoint already has link to: ${endpoint.name}`);
        }
        endpoint.setHref(this.getHref().concat('/', endpoint.name));
        this.links.set(endpoint.name, endpoint);
    }

    public setService(service : CBService){
        this.service = service;
    }

    public getLinks() : CBLink[]{
        const links : CBLink[] = [];
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