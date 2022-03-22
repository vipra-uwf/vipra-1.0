
class UserRepo_Mock{
    constructor(){}

    async FindUser(email){
        return {
            email: "testemail@test.com",
            password: "testpassword",
            group: "testGroup",
            roles: [
                "USER"
            ]
        }
    }

    async RegisterUser(userID, user){
        return true;
    }
}

module.exports = UserRepo_Mock;