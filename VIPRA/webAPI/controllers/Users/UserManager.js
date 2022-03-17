
const randomUUID = require('crypto').randomUUID;

class UserManager{
    constructor(UserRepo){
        this._UserRepo = UserRepo;
    }

    async GetUser(userID){
        // TODO return user information
    }

    async RemoveUser(userID){
        // TODO allow users to be removed
    }

    async EditUser(userID, newUser){
        // TODO allow users to be updated
    }

    // NOTE: the request is assumed to have passed through checkRegistration
    async RegisterUser(request){
        const user = request.body;
        if(await this._UserRepo.RegisterUser(user)){
            return userID;
        }else{
            return null;
        }
    }
}


module.exports = UserManager;