
const jwt = require('jsonwebtoken')

const DecodeToken = async (request, jwt_secret)=>{
    console.log("Decoding");
    const token = request.header("x-access-token");

    if(token){
        jwt.verify(token, jwt_secret, (err, decoded)=>{
            if(err){return null;}
            return decoded;
        });
    }else{
        return null;
    }
}

class Authentication_JWT{

    constructor(PasswordManager, Database, jwt_secret, jwt_expiration){
        this._PasswordManager = PasswordManager;
        this._jwt_secret = jwt_secret;
        this._jwt_expiration = jwt_expiration;
        this._db = Database;
    }

    async _MakeToken(user){
        
        const payload = {
            "email": user.email,
            "group": user.group,
            "roles": user.roles
        }

        return jwt.sign(payload,this._jwt_secret,{expiresIn: this._jwt_expiration});
    }

    async GetToken(request){

        const loginCreds = request.body.user;

        if(!(loginCreds.email && loginCreds.password)){
            return null;
        }

        const user = await this._db.findUser(loginCreds.email);
        if(user){
            if(await this._PasswordManager.CheckPassword(loginCreds.password, user.password)){
                return await this._MakeToken(user);
            }
        }
        return null;
    }
}

module.exports = {
    "Authenticator": Authentication_JWT,
    "Decode": DecodeToken
}