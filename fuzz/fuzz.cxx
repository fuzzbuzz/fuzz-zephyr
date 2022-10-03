#include <stdint.h>
#include <stddef.h>
#include "fuzzbuzz.hxx"

extern "C" int LLVMFuzzerTestOneInput(uint8_t *, size_t);

FZBZ_TARGET_CLASS(FuzzLLVMFuzzerTestOneInput);
struct FuzzLLVMFuzzerTestOneInput {
	FuzzLLVMFuzzerTestOneInput(fzbz::Fuzzer &f) {
		auto data = fzbz::generator::byteArray<std::vector<uint8_t>>();
		data.setMaxLength(4096);
		auto target = fzbz::fuzzTarget([](auto data) {
			LLVMFuzzerTestOneInput(&(data[0]), data.size());
		}, data);
		f.addFuzzTarget(target);
	}
};
