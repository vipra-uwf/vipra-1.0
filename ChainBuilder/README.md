# Simple Example: Addition Service
1. Creating a CBServiceRoot
2. Creating a ResultStore
3. Creating a Service
4. Putting it together
5. Creating a HTTP server
---
## 1. Creating a CBServiceRoot
The first step is to create a `CBServiceRoot`, this is what holds services and routes requests.
- Provide the `CBServiceRoot` Constructor with the base URL for accessing the hosting server
```typescript
const  cbroot : CBServiceRoot = new  CBServiceRoot('example.com:3000');
```
! ChainBuilder requires HTTPS, we are using HTTP for simplicity !

---
## 2. Creating a ResultStore
Secondly, a `ResultStore` is needed to keep any results from your service

```typescript
class SumResultStore extends ResultStore {
	private results : Map<string, string>;
	storeResult(args: CbArgs, result: string): CbResult { }
	getResult(hash: string): CbResult { }
}
```
A ResultStore has two member functions that need overridden
1. `storeResult`
2. `getResult`

In this example both return `CbResult`, as there is no I/O involved.
However, `storeResult` and `getResult` can return either a `CbResult` or `Promise<CbResult>`

**1. storeResult**

`storeResult` is called after each time the service is run, with the `CbArgs` used to run the `Service` and the result.

A `CbResult` is returned:
-	`error` indicates whether an error has occurred while storing the result
- `result` is the identifier for the result
	- `result` will be used by ChainBuilder to request the result from `getResult` in the future
	- if `error` is `true`, `result` should be used to return the error message *(this message will be visible to ChainBuilder)*
```typescript
  public storeResult(args: CbArgs, result: string): CbResult {
    const location = createHash('sha512').update(args.addend.reduce((prev, curr)=>prev + curr)).digest('hex');
    this.results.set(location, result);
    return { error : false, result : location };
  }
```
In this example, we run a hash over the arguments and the service results are stored in a `Map<string, string>`.
With the key being the hash, and the value our result.

**2. getResult**

`getResult` is called when ChainBuilder requests a result, `locationID` coming from result in the return value of `storeResult` .

The return value is similar to `storeResult` with the difference that `result` should be the actual resulting value from running the service as opposed to an identifier.

```typescript
  public getResult(locationID: string): CbResult {
    const result = this.results.get(locationID);
    if (result) { 
      return { error : false, result };
    }
    return { error : true, result : 'No Result at that location' };
  }
```
In this example we access the results Map and return the result.

If there is no result with at `locationID` in the Map we return that an error has occurred.

---
## 3. Creating a Service
**3.1 Adding Service Information**

First we will add the front facing information for potential ChainBuilder users of our service.

This is done using `CbServiceInfo`, we will create `info` to hold out service information.
```typescript
const info : CbServiceInfo = {
  name: 'addition',
  description: 'sums two numbers',
  key: 'wartjartvadrvaerhrtjabv',
  version: '1.0.0',
  author: 'example author',
  email: 'example@email.com',
  doc_href: 'example.com',
};
```
`key` and `version` are the key values here as ChainBuilder uses these to identify services
The other values are simply for Human Use.

Duplicate `Service`s hosted on other servers/routes should, ideally, have the same `key` and `version`.

**3.2 Adding Functionality**

We need to create the actual functionality of our service using `CbMethod`.

A `CbMethod` is a function that takes in a `CbArgs` object and returns a `CbResult` or `Promise<CbResult>`.

```typescript
const sum = (args: CbArgs) : CbResult => {
	const addends : string[] = args.addend;
	const result = addends.reduce( (previousValue, currentValue) => ((+previousValue) + (+currentValue)).toString() );

	return { error : false, result };
};
```
*`args` contains all arguments passed to the service from ChainBuilder, the names of these arguments are discussed in the next section.*

In this example our `CbMethod` expects an `addend`, we do a simple reduce operation to add the arguments together and return the result, **as a string**.

! Checking for Incorrect arguments is up to the user !

`Service` ensures that the `CbMethod` is called with all of the expected parameters, no missing and no more. It makes NO guarantees that the arguments are of the correct type or count.

**3.3 CbServiceOptions**

`CbServiceOptions` is where the implementation for the service is added
```typescript
const opts : CbServiceOptions = {
  info,
  returnValue: {
    name: 'sum',
    type: 'float',
  },
  resultStore: new SumResultStore('sums'),
  method: sum,
  parameters: [
    {
      name: 'addend',
      type: 'float',
      description: 'addend',
      sample: '10',
    },
  ],
  server: [],
};
```
- `info` is the `CbServiceInfo` we created in the step above
- `returnValue` tells ChainBuilder the name and type of Service results
	- These are used to connect with other ChainBuilder Services
- `resultStore` is the `ResultStore` implementation the service uses, in our case a newly constructed `SumResultStore`
	- `ResultStore`s MAY be reused by multiple services, however it is not advised
- `method` is the `CbMethod` the service uses, in our case `sum`
- `parameters` are the parameters `method` expects to receive
- `server` server options explained in `TODO` section

**3.4 Creating the Service**

Lastly we put the parts together to create the `Service`

```typescript
const addService : Service = new Service(opts);
```

## 4. Adding the Service

Having created the `Service` we add it to the `CBServiceRoot`
```typescript
cbroot.addService(addService, '/services/example/');
```
In this example the new service can be reached at `example.com/services/example/`

## 5. Creating a HTTP server

`CbServerRoot` does not host a HTTP server itself and as such depends on [ExpressJS](https://github.com/expressjs/express)
To be able to access our `Service` we need to create an simple express app

```typescript
const app = express();

app.use('/', (req : express.Request, res : express.Response)=>{
  cbroot.handleChainBuilderRequest(req, res);
});

app.listen(3000);
```
Calling `handleChainBuilderRequest` with the request and response from ChainBuilder is all that is required.

**IMPORTANT:
!! ChainBuilder requires HTTPS !!**
in this example HTTP is used as a simplification

---
# Full Example: Addition Service 
Below is the Full code for the Addition Service Example
```typescript
// ---- Creating CBServiceRoot ------------------------------------
const cbroot : CBServiceRoot = new CBServiceRoot('https://example.com');

// ---- Creating ResultStore --------------------------------------
class SumResultStore extends ResultStore {
  private results : Map<string, string>;
  
  constructor(name : string) {
    super(name);
    this.results = new Map();
  }

  public getResult(locationID: string): CbResult {
    const result = this.results.get(locationID);
    if (result) { 
      return { error : false, result };
    }
    return { error : true, result : 'No Result at that location' };
  }

  public storeResult(args: CbArgs, result: string): CbResult {
    const location = createHash('sha512').update(args.addend.reduce((prev, curr)=>prev + curr)).digest('hex');
    this.results.set(location, result);
    return { error : false, result : location };
  }
}

// ----- Creating Service -----------------------------------------

const info : CbServiceInfo = {
  name: 'addition',
  description: 'sums two numbers',
  key: '67m46eMv&SKhittjmP4zvD&Il',
  version: '1.0.0',
  author: 'example author',
  email: 'example@email.com',
  doc_href: 'example.com',
};

const sum = (args: CbArgs) : CbResult => {
	const addends : string[] = args.addend;
	const result = addends.reduce( (previousValue, currentValue) => ((+previousValue) + (+currentValue)).toString() );

	return { error : false, result };
};

const opts : CbServiceOptions = {
  info,
  returnValue: {
    name: 'sum',
    type: 'float',
  },
  resultStore: new SumResultStore('sums'),
  method: sum,
  parameters: [
    {
      name: 'addend',
      type: 'float',
      description: 'addend',
      sample: '10',
    },
  ],
  server: [CbResultOptions.TRANSIENT],
};
const newService : Service = new Service(opts);

// ---- Adding the New Service ----------------------------
cbroot.addService(newService, '/services/test/');

const app = express();

app.use('/', (req : express.Request, res : express.Response)=>{
  cbroot.handleChainBuilderRequest(req, res);
});

app.listen(3001, ()=>{
  console.log('listening');
});
```