

const express = require('express');
const config = require('../configurations/config');

const { checkRegistration } = require('../middleware/checkRegistration');
const { authenticate }    = require('../middleware/authenticate');

const { Status }        = require('../configurations/Status');

const PasswordManager   = new config.users.PasswordManager();
const Authenticator     = new config.authentication.Authenticator(PasswordManager, config.authentication.JWT_SECRET, config.authentication.JWT_EXPIRATION);
const UserRepo          = new config.repos.UserRepo(config.database.UserDB_Con);
const UserManager       = new config.users.UserManager(UserRepo, Authenticator, PasswordManager);

const router = express.Router();

router.use(authenticate);

router.post('/login', (req, res)=>{
    UserManager.Login(req)
    .then((jwt)=>{
        if(jwt){
            res.status(200).json({message: "Success", token: jwt});
        }else{
            res.status(400).json({error: "Bad Request", detail: "Invalid Username or Password"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in login: " + err);
        res.status(500).json({error: "Unable to login", detail: "An Unknown error occured on the server"});
    });
});

router.post('/register', checkRegistration, (req, res)=>{
    UserManager.RegisterUser(req)
    .then((created)=>{
        switch(created){
            case Status.SUCCESS:
                res.status(200).json({message: "User Created"});
                break;
            case Status.BAD_REQUEST:
                res.status(400).json({error: "Bad Request", detail: "Cannot Register Duplicate Users"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Register User`);
                res.status(500).json({error: "Unable to register new user", detail: "An Unknown error occured on the server"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Register: " + err);
        res.status(500).json({error: "Unable to register new user", detail: "An Unknown error occured on the server"});
    });
});

router.delete('/users/:userEmail', (req, res)=>{
    UserManager.RemoveUser(req.params.userEmail, req.Auth)
    .then((removed)=>{
        switch(removed){
            case Status.SUCCESS:
                res.status(200).json({message: "User Removed"});
                break;
            case Status.BAD_REQUEST:
                res.status(400).json({error: "Bad Request", detail: "No User With that Email"});
                break;
            case Status.UNAUTHORIZED:
                res.status(401).json({error: "Unauthorized", detail: "Not Authorized to access this resource"});
                break;
            default:
                console.log(`[ERROR] Unhandled status in Remove User`);
                res.status(500).json({error: "Unable to Delete User", detail: "An Unknown error occured on the server"});
        }
    })
    .catch((err)=>{
        console.log(`[ERROR] Error in Remove User: ${err}`);
        res.status(500).json({error: "Unable to Delete User", detail: "An Unknown error occured on the server"});
    });
});

module.exports = router;