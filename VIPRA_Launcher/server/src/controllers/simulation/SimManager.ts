import { ConfigManager } from "../simconfig/ConfigManager";


export class SimManager{

    private configManager : ConfigManager;

    constructor(configManager : ConfigManager){
        this.configManager = configManager;
    }

    startSimWithConfig(id: string) {
        throw new Error('Method not implemented.');
    }


}