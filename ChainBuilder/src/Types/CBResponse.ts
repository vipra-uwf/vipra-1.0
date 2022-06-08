import { IncomingMessage, Server, ServerResponse } from 'http';
import { CBLink } from './CBLink';
import { Parameter } from './Parameter';
import { ServiceInfo } from './ServiceInfo';

interface CBResponse{
    name:
    {
        description     : string,
        type            : string,
        sample?         : string,
        sample_href?    : string
    };
}

const cbRespond = (response : CBResponse, res : ServerResponse) : void => {
    // TODO
};

const cbLinksRespond = (links : CBLink[], res : ServerResponse) : void =>{
    res.end(JSON.stringify(
        {
            status: 'success',
            links
        }));
};

const cbErrorRespond = (message : string, response : ServerResponse) : void => {
    response.statusCode = 200;
    response.end(`{
        'status': error,
        'message': ${message}
\   }`);
};

const cbServiceInfoRespond = (info : ServiceInfo, parameters : Parameter[], responses : CBResponse[], res : ServerResponse) : void => {
    res.end(JSON.stringify({
        info,
        methods:['GET', 'POST'],
        status: 'success',
        parameters,
        responses
    }));
}

export {
    CBResponse,
    cbRespond,
    cbErrorRespond,
    cbLinksRespond,
    cbServiceInfoRespond
};