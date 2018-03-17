build-debian:
	rm -rf build
	docker build -t southclaws/bitmapper-build .
	docker run -v $(shell pwd)/test/plugins:/root/test/plugins southclaws/bitmapper-build

build-inside:
	cd build && cmake .. && make

server-test:
	sampctl package build
	cd test && sampctl server run --container --mountCache

server-test-windows:
	cp test/plugins/Debug/bitmapper.dll test/plugins/bitmapper.dll
	sampctl package build --forceEnsure
	cd test && sampctl server run

build-e2e: build-debian server-test
	echo SUCCESS!
