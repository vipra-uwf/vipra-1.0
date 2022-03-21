
const bcrypt = require('bcrypt')

const SaltRounds = 2 ** 10;

class PasswordManager_bcrypt{
    constructor(){}


    // TODO!! this will produce the same hash if two users use the same password, need to add a way to change this -RG
    async HashPassword(password){
        return bcrypt.hash(password, SaltRounds);
    }

    async CheckPassword(password, dbpassword){
        return bcrypt.compare(password, dbpassword);
    }
}

module.exports = PasswordManager_bcrypt;