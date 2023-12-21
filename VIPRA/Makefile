BASE_DIR = ./Base
CODE_GEN_DIR = ${BASE_DIR}/code_generation

release:
	make build DEBUG=-DDEBUG_MODE=OFF PROF=-DPROF_MODE=OFF DIR=build

debug:
	make build DEBUG=-DDEBUG_MODE=ON PROF=-DPROF_MODE=OFF DIR=build_debug

profiling:
	make build DEBUG=-DDEBUG_MODE=OFF PROF=-DPROF_MODE=ON DIR=build

build: build_gen_main run_gen_main build_sim

manual_bhvrs:
	make build DEBUG=-DDEBUG_MODE=OFF PROF=-DPROF_MODE=OFF DIR=build_bhvr_perf_testing BHVR_PERF_TESTING=-DMAN_BHVRS=ON

# start_server:
# 	node ../VIPRA_Launcher/server/dist/index.js -noserver -nobuild

build_gen_main:
	mkdir -p ${CODE_GEN_DIR}/${DIR}
	cmake -B ${CODE_GEN_DIR}/${DIR} ${CODE_GEN_DIR} ${DEBUG} ${BHVR_PERF_TESTING}
	cmake --build ${CODE_GEN_DIR}/${DIR}

run_gen_main:
	${CODE_GEN_DIR}/generate_main main.cpp ./modules.json -noCompReq

build_sim:
	mkdir -p params
	mkdir -p output
	mkdir -p ${DIR}
	cmake -B ${DIR} . ${DEBUG} ${PROF} ${BHVR_PERF_TESTING}
	cmake --build ${DIR} -j 5
	
clean:
	rm -rf build
	rm -rf build_debug
	rm -rf ${CODE_GEN_DIR}/build
	rm -rf ${CODE_GEN_DIR}/build_debug
	rm -f main.cpp
	rm -f VIPRA_SIM

.PHONY:
	start_server
	set_release
	build_gen_main
	run_gen_main
	build_sim
	clean