
class BehaviorRepo_Mock{
    constructor(){}

    Load(behaviorID){
        if(behaviorID === 'notarealid'){
            return {'behaviorID': behaviorID,
                    'name': 'test_behavior',
                    'content': `Consider an injured-person.
                                Exactly 1 random pedestrian is an injured-person.
                                An injured-person can be INJURED.
                                An injured-person who is INJURED will walk 5% slower.`
                    }
        }else{
            return null;
        }
    }

    Save(name, content, publish){
        return name;
    }

    LoadOptions(){
        return ({
            'behaviors': [
                {
                    'name': 'injured_person'
                },
                {
                    'name': 'example'
                }
            ]
        });
    }
}

module.exports = BehaviorRepo_Mock;