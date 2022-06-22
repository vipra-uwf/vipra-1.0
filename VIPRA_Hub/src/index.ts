import express from "express";
import { config } from "./configuration/config";
import { Logger } from "./logging/Logging";
import { BehaviorRoutes } from "./routes/behaviorRoutes";
import { defaultRouter } from "./routes/defaultRoutes";
import { MapRoutes } from "./routes/mapRoutes";
import { ModuleRoutes } from "./routes/moduleRoutes";

const app = express();

app.use(express.urlencoded({extended: true}));
app.use(express.json());

app.use('/module',      ModuleRoutes);
app.use('/behavior',    BehaviorRoutes);
app.use('/map',         MapRoutes);
app.use('*',            defaultRouter);

app.listen(config.port, ()=>{
    Logger.info(`Listening on: ${config.port}`);
});