class UpdateManager_NoUpdates{
    constructor(SimManager){}

    async ProvideUpdates(configID, response){
        response.status(404).json({error: "Not Found", detail: "Simulation Updates are not enabled"});
    }
}

module.exports = UpdateManager_NoUpdates