
const config = require('../configurations/config')
const decode = config.authentication.DecodeToken;


const authenticate = async (req, res, next)=>{
    req.Auth = await decode(req, config.authentication.JWT_SECRET);
    next();
};


module.exports = {
    authenticate
}