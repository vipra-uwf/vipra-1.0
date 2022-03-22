const { Status } = require('../../configurations/Status');

class UserManager{

    #authenticator;
    #passManager;
    #UserRepo;

    constructor(UserRepo, Authenticator, PasswordManager){
        this.#CheckParams(UserRepo, Authenticator, PasswordManager);
        this.#authenticator = Authenticator;
        this.#passManager = PasswordManager;
        this.#UserRepo = UserRepo;
    }

    #CheckParams(repo, auth, pass){
        if(repo === null){
            throw `[FATAL] User Repo is null`;
        }
        if(auth === null){
            throw `[FATAL] User Authentication is null`;
        }
        if(pass === null){
            throw `[FATAL] User Password Manager is null`;
        }
    }

    async RemoveUser(email, Auth){
        if(Auth){
            if(email === Auth.email){
                const deleted = await this.#UserRepo.DeleteUser(email);
                if(deleted){
                    return Status.SUCCESS;
                }else{
                    return Status.BAD_REQUEST;
                }
            }
        }
        return Status.UNAUTHORIZED;
    }

    async EditUser(newUser){
        // TODO allow users to be updated, not needed till we add more fields -RG
    }

    async Login(request){
        const user = request.body.user;
        const dbUser = await this.#UserRepo.FindByEmail(user.email);
        if(dbUser !== null){
            return await this.#authenticator.GetToken(user, dbUser);
        }else{
            return null;
        }
    }

    // NOTE: the request is assumed to have passed through checkRegistration -RG
    async RegisterUser(request){
        const user = request.body.user;
        user.password = await this.#passManager.HashPassword(user.password);
        const created = await this.#UserRepo.RegisterUser(user.email, user.password);
        if(created){
            return Status.SUCCESS;
        }else{
            return Status.BAD_REQUEST;
        }
    }
}


module.exports = UserManager;