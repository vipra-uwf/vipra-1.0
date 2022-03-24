# Build
## External Libraries
- Antlr4
	- generates lexer & parser for dsl grammar
	- definition of grammar in `VIPRA/Behavior.g4`
- rapidxml
	- parses xml
	- used in `VIPRA/readers/input_xml_reader` & `VIPRA/writers/xml_writer`



## 1. Compile `generate_main.exe`
1. In `VIPRA/`
2. run command `make`
- **Necessary Files:**
	- `VIPRA/code_generation/code_generator.cpp` 
	- `VIPRA/jsoncpp/jsoncpp.cpp`
	- `VIPRA/configuration/configuration_reader.cpp`

## 2. Generate `generated_main.cpp`
1. In `VIPRA/`
2. run command `./generate_main *id*`
	- `*id*` is the id for a staged sim_config
- **Necessary Files:**
	- `VIPRA/input_data/includes_map.json`

## 3. Compile `generated_main.cpp`
1. in `webAPI/`
2. run command `make *id*`
	- `*id*` is the id for a staged sim_config
- **Necessary Files:**
	- `all object files`

## 4. Run `generated_main`
1. in `VIPRA/input_data/**id**/`
	- `*id*` is the id for a staged sim_config
2. run command `generated_main`
- **Necessary Files:**
	- `sim_config.json`
	- `sim_params.json`
	- `any behaviors files specified in sim_config`
		- searches for behaviors with relative path `./../behaviors`