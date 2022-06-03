export interface Map{
    name: string;
    content: string;
    description: string;
    creator: string;
    publish: boolean;
}

export const CheckMap = (map : any) => {

    if(!map){
        return false;
    }

    if(map.name && map.content && map.description && map.creator && map.publish){
        if(CheckTypes(map.name, map.content, map.description, map.creator, map.publish)){
            return true;
        }
        return false;
    }
    return false;
};

const CheckTypes = (name : any, content : any, description : any, creator : any, publish : any)=>{
    return (
        typeof(name) === "string" &&
        typeof(content) === "string" &&
        typeof(description) === "string" &&
        typeof(creator) === "string" &&
        typeof(publish) === "boolean"
    );
};