import express from "express";
import { BehaviorRoutes } from "./routes/behaviorRoutes";
import { MapRoutes } from "./routes/mapRoutes";
import { ModelRoutes } from "./routes/modelRoutes";

const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.json());

app.use('/model', ModelRoutes);
app.use('/behavior', BehaviorRoutes);
app.use('/map', MapRoutes);

app.listen(3000, ()=>{
    // tslint:disable-next-line:no-console
    console.log("Listening");
});