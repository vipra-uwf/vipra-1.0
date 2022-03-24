

// TODO move functionality to UserManager

const checkRegistration = async (req, res, next)=>{
    if(req.body.user){
        const user = req.body.user;
        if(user){
            // TODO check that the email is properly formatted -RG
            if(user.email){
                if(user.password){
                    next();
                }else{
                    res.status(400).json({message: "Bad Request", detail: "No Password was provided"});
                }
            }else{
                res.status(400).json({message: "Bad Request", detail: "No User Email was provided"});
                
            }
        }
    }else{
        res.status(400).json({message: "Bad Request", detail: "No User info was provided"});
    }
}

module.exports = {
    checkRegistration
}