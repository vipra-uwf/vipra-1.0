

const express = require('express');
const config = require('../configurations/config')

const { checkRegistration } = require('../middleware/checkRegistration');

const UserRepo          = new config.repos.UserRepo();
const PasswordManager   = new config.users.PasswordManager();
const Authentication    = new config.authentication.Authenticator(PasswordManager, UserRepo, config.users.JWT_SECRET, config.users.JWT_EXPIRATION);
const UserManager       = new config.users.UserManager();

const router = express.Router();

router.post('/login', (req, res)=>{
    Authentication.GetToken(req)
    .then((jwt)=>{
        console.log(jwt);
        if(jwt){
            res.status(200).json({message: "Success", token: jwt});
        }else{
            res.status(400).json({message: "Invalid Username or Password"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in login: " + err);
        res.status(500).json({message: "Unable to login"});
    });
});

router.post('/register', checkRegistration, (req, res)=>{
    UserManager.RegisterUser(req)
    .then((userID)=>{
        if(userID){
            res.status(200).json({message: "Success", "userID": userID});
        }else{
            res.status(500).json({message: "Unable to register new user"});
        }
    })
    .catch((err)=>{
        console.log("[ERROR] Error in Register: " + err);
        res.status(500).json({message: "Unable to register new user"})
    });
});


module.exports = router;