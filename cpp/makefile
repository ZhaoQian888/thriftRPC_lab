BUILD_DIR = ./build/
DEST_DIR = ./bin/
DEST_EXE_NAME1 = server
DEST_EXE_NAME2 = client
all: build
	cd $(BUILD_DIR);
	make -j4
run:
	cd $(DEST_DIR); ./$(DEST_EXE_NAME)
clean:
	rm -rf $(BUILD_DIR) 
	rm -rf $(DEST_DIR) 
build:
	mkdir -p  $(DEST_DIR)
	mkdir -p  $(BUILD_DIR);cd $(BUILD_DIR);cmake ..;make
	mv $(BUILD_DIR)$(DEST_EXE_NAME1) $(BUILD_DIR)$(DEST_EXE_NAME2)  ./bin