# -
# Setup test requirements
# -

test-setup:
	cd test && sampctl server ensure
	sampctl package ensure

# -
# Run Tests
# -

test-windows:
	sampctl package build
	cd test && sampctl server run

test-linux:
	sampctl package build
	cd test && sampctl server run --container --mountCache

# -
# Linux
# -

build-linux:
	rm -rf build
	docker build -t southclaws/bitmapper-build .
	docker run -v $(shell pwd)/test/plugins:/root/test/plugins southclaws/bitmapper-build

build-inside:
	cd build && cmake .. && make
