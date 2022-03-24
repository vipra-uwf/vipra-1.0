const jwt = require('jsonwebtoken');

const DecodeToken = async (request, jwt_secret)=>{
    const token = request.header("Authorization");
    if(token){
        return await jwt.verify(token, jwt_secret, (err, decoded)=>{
            if(err){
                console.log(`[ERROR] Error in DecodeToken: ${err}`);
                return null;
            }
            return decoded;
        });
    }else{
        return null;
    }
}

class Authenticator_JWT{

    #passManager;
    #jwt_secret;
    #jwt_expiration;

    // TODO: change this to accept an options JSON Object, that contains jwt_secret and jwt_expiration
    constructor(PasswordManager, jwt_secret, jwt_expiration){
        this.#CheckParams(PasswordManager, jwt_secret, jwt_expiration);
        this.#passManager = PasswordManager;
        this.#jwt_secret = jwt_secret;
        this.#jwt_expiration = jwt_expiration;
    }

    #CheckParams(passManager, jwt_secret, jwt_expiration){
        if(passManager === null){
            throw `[FATAL] Authenticator Password Manager is null`;
        }
        if(jwt_secret === null){
            throw `[FATAL] Authenticator JWT_SECRET is null`;
        }
        if(jwt_expiration === null){
            throw `[FATAL] Authenticator JWT_EXPIRATION is null`;
        }
    }

    async #MakeToken(user){
        // TODO add any permissions information needed -RG
        const payload = {
            email: user.email
        }
        return jwt.sign(payload, this.#jwt_secret,{ expiresIn: this.#jwt_expiration });
    }

    async GetToken(user, dbUser){
        const passed = await this.#passManager.CheckPassword(user.password, dbUser.password);
        if(passed){
            return this.#MakeToken(user);
        }else{
            return null;
        }
    }
};

module.exports = {
    Authenticator: Authenticator_JWT,
    DecodeToken: DecodeToken
}