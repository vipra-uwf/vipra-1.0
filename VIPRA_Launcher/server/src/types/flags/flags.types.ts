export enum FLAGS {
  FLAGS_FILE     = '-flagsfile', // Path to file containing flags
  DEBUG_BUILD    = '-debugbuild', // Builds the simulation with debug flags
  DEBUG_RUN      = '-debugrun', // Runs the Simulation after each SUCCESS SimBuild event
  DEBUG_MAP      = '-debugmap', // Overrides map file input with path provided
  DEBUG_PEDS     = '-debugpeds', // Overrides pedestrian file with path provided
  DEBUG_PARAMS   = '-debugparams', // Overrides parameter input and uses the parameter file at the provided path
  DEBUG_CONFIG   = '-debugconfig', // Overrides configID provided to simulation
  DEBUG_OUTPUT   = '-debugoutput', // Overrides output location for simulation run
  VIPRA_DIR      = '-vipradir', // Sets the Path to the VIPRA directory
  NO_SERV        = '-noserver', // Runs Launcher without starting a HTTP/HTTPS server
  NO_BUILD_CLEAN = '-noclean', // Simulation Builds will NOT clean up build files
  NO_BUILD       = '-nobuild', // Simulation is NOT built on startup
  CERTS_DIR      = '-certs', // Sets the Path to the HTTPS certifications directory
}