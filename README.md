# magic_enum + protobuf Crash Reproduction

## Build and Run

```bash
export VCPKG_ROOT=/path/to/vcpkg
cmake --preset default
cmake --build build
./build/magic_enum_protobuf_repro
```

Output:

```text
> protobuf-magic_enum-repro % lldb ./build/magic_enum_protobuf_repro
(lldb) target create "./build/magic_enum_protobuf_repro"
Current executable set to '/Users/XX/dev/protobuf-magic_enum-repro/build/magic_enum_protobuf_repro' (arm64).
(lldb) r
Process 57912 launched: '/Users/XX/dev/protobuf-magic_enum-repro/build/magic_enum_protobuf_repro' (arm64)
Process 57912 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x53707937)
    frame #0: 0x0000000100002b44 magic_enum_protobuf_repro`std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ne190102](this="") const at string:1881:29
   1878     if (__libcpp_is_constant_evaluated() && __builtin_constant_p(__r_.first().__l.__is_long_)) {
   1879       return __r_.first().__l.__is_long_;
   1880     }
-> 1881     return __r_.first().__s.__is_long_;
   1882   }
   1883
   1884   static _LIBCPP_HIDE_FROM_ABI _LIBCPP_CONSTEXPR_SINCE_CXX20 void __begin_lifetime(pointer __begin, size_type __n) {
Target 0: (magic_enum_protobuf_repro) stopped.
(lldb) bt
* thread #1, queue = 'com.apple.main-thread', stop reason = EXC_BAD_ACCESS (code=1, address=0x53707937)
  * frame #0: 0x0000000100002b44 magic_enum_protobuf_repro`std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ne190102](this="") const at string:1881:29
    frame #1: 0x0000000100002e80 magic_enum_protobuf_repro`std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ne190102](this="") const at string:2009:12
    frame #2: 0x0000000100002574 magic_enum_protobuf_repro`std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data[abi:ne190102](this="") const at string:1705:30
    frame #3: 0x00000001000063fc magic_enum_protobuf_repro`absl::lts_20250127::string_view::string_view<std::__1::allocator<char>>(this=0x000000016fdf8f78, str="") at string_view.h:193:25
    frame #4: 0x0000000100243e28 magic_enum_protobuf_repro`google::protobuf::internal::TcParser::FastSS1(google::protobuf::MessageLite*, char const*, google::protobuf::internal::ParseContext*, google::protobuf::internal::TcFieldData, google::protobuf::internal::TcParseTableBase const*, unsigned long long) [inlined] google::protobuf::internal::(anonymous namespace)::IsValidUTF8(field=0x000000016fdf9398) at generated_message_tctable_lite.cc:1402:42
    frame #5: 0x0000000100243e14 magic_enum_protobuf_repro`google::protobuf::internal::TcParser::FastSS1(google::protobuf::MessageLite*, char const*, google::protobuf::internal::ParseContext*, google::protobuf::internal::TcFieldData, google::protobuf::internal::TcParseTableBase const*, unsigned long long) [inlined] char const* google::protobuf::internal::TcParser::SingularString<unsigned char, google::protobuf::internal::ArenaStringPtr, (google::protobuf::internal::TcParser::Utf8Type)2>(msg=0x000000016fdf92e8, ptr="\U00000012\aexample\"1\n\U00000006Person\U00000012\f\n\U00000004name\U00000018\U00000001 \U00000001(\t\U00000012\n\n\U00000002id\U00000018\U00000002 \U00000001(\U00000005\U00000012\r\n\U00000005email\U00000018\U00000003 \U00000001(\t\".\n\vAddressBook\U00000012\U0000001f\n\U00000006people\U00000018\U00000001 \U00000003(\v2\U0000000f.example.Personb\U00000006proto3", ctx=0x000000016fdf90a8, data=TcFieldData @ 0x000000016fdf8e48, table=0x000000010047d0d0, hasbits=1) at generated_message_tctable_lite.cc:1435:11
    frame #6: 0x0000000100243c2c magic_enum_protobuf_repro`google::protobuf::internal::TcParser::FastSS1(msg=0x000000016fdf92e8, ptr="\n\rexample.proto\U00000012\aexample\"1\n\U00000006Person\U00000012\f\n\U00000004name\U00000018\U00000001 \U00000001(\t\U00000012\n\n\U00000002id\U00000018\U00000002 \U00000001(\U00000005\U00000012\r\n\U00000005email\U00000018\U00000003 \U00000001(\t\".\n\vAddressBook\U00000012\U0000001f\n\U00000006people\U00000018\U00000001 \U00000003(\v2\U0000000f.example.Personb\U00000006proto3", ctx=0x000000016fdf90a8, data=TcFieldData @ 0x000000016fdf8de8, table=0x000000010047d0d0, hasbits=0) at generated_message_tctable_lite.cc:1457:28
    frame #7: 0x00000001002ae318 magic_enum_protobuf_repro`bool google::protobuf::internal::MergeFromImpl<false>(absl::lts_20250127::string_view, google::protobuf::MessageLite*, google::protobuf::internal::TcParseTableBase const*, google::protobuf::MessageLite::ParseFlags) [inlined] google::protobuf::internal::TcParser::TagDispatch(msg=0x000000016fdf92e8, ptr="\n\rexample.proto\U00000012\aexample\"1\n\U00000006Person\U00000012\f\n\U00000004name\U00000018\U00000001 \U00000001(\t\U00000012\n\n\U00000002id\U00000018\U00000002 \U00000001(\U00000005\U00000012\r\n\U00000005email\U00000018\U00000003 \U00000001(\t\".\n\vAddressBook\U00000012\U0000001f\n\U00000006people\U00000018\U00000001 \U00000003(\v2\U0000000f.example.Personb\U00000006proto3", ctx=0x000000016fdf90a8, (null)=TcFieldData @ 0x000000016fdf90a0, table=0x000000010047d0d0, hasbits=0) at generated_message_tctable_impl.h:1105:28
    frame #8: 0x00000001002ae264 magic_enum_protobuf_repro`bool google::protobuf::internal::MergeFromImpl<false>(absl::lts_20250127::string_view, google::protobuf::MessageLite*, google::protobuf::internal::TcParseTableBase const*, google::protobuf::MessageLite::ParseFlags) [inlined] google::protobuf::internal::TcParser::ParseLoop(msg=0x000000016fdf92e8, ptr="\n\rexample.proto\U00000012\aexample\"1\n\U00000006Person\U00000012\f\n\U00000004name\U00000018\U00000001 \U00000001(\t\U00000012\n\n\U00000002id\U00000018\U00000002 \U00000001(\U00000005\U00000012\r\n\U00000005email\U00000018\U00000003 \U00000001(\t\".\n\vAddressBook\U00000012\U0000001f\n\U00000006people\U00000018\U00000001 \U00000003(\v2\U0000000f.example.Personb\U00000006proto3", ctx=0x000000016fdf90a8, table=0x000000010047d108) at generated_message_tctable_impl.h:1147:11
    frame #9: 0x00000001002ae1e8 magic_enum_protobuf_repro`bool google::protobuf::internal::MergeFromImpl<false>(input=(ptr_ = "\n\rexample.proto\U00000012\aexample\"1\n\U00000006Person\U00000012\f\n\U00000004name\U00000018\U00000001 \U00000001(\t\U00000012\n\n\U00000002id\U00000018\U00000002 \U00000001(\U00000005\U00000012\r\n\U00000005email\U00000018\U00000003 \U00000001(\t\".\n\vAddressBook\U00000012\U0000001f\n\U00000006people\U00000018\U00000001 \U00000003(\v2\U0000000f.example.Personb\U00000006proto3", length_ = 131), msg=0x000000016fdf92e8, tc_table=0x000000010047d0d0, parse_flags=kParse) at message_lite.cc:218:9
    frame #10: 0x00000001002b20c8 magic_enum_protobuf_repro`bool google::protobuf::MessageLite::ParseFrom<(google::protobuf::MessageLite::ParseFlags)1, absl::lts_20250127::string_view>(this=0x000000016fdf92e8, input=0x000000016fdf9218) at message_lite.h:1149:10
    frame #11: 0x00000001002b2370 magic_enum_protobuf_repro`google::protobuf::MessageLite::ParseFromArray(this=0x000000016fdf92e8, data=0x000000010044ddd0, size=131) at message_lite.cc:409:10
    frame #12: 0x0000000100144c8c magic_enum_protobuf_repro`google::protobuf::EncodedDescriptorDatabase::Add(this=0x0000000153707830, encoded_file_descriptor=0x000000010044ddd0, size=131) at descriptor_database.cc:547:12
    frame #13: 0x000000010001d504 magic_enum_protobuf_repro`google::protobuf::DescriptorPool::InternalAddGeneratedFile(encoded_file_descriptor=0x000000010044ddd0, size=131) at descriptor.cc:2248:3
    frame #14: 0x0000000100203fe8 magic_enum_protobuf_repro`google::protobuf::(anonymous namespace)::AddDescriptorsImpl(table=0x000000010047c058) at generated_message_reflection.cc:3712:3
    frame #15: 0x0000000100203f3c magic_enum_protobuf_repro`google::protobuf::internal::AddDescriptors(table=0x000000010047c058) at generated_message_reflection.cc:3727:3
    frame #16: 0x00000001000062d8 magic_enum_protobuf_repro`::__cxx_global_var_init() at example.pb.cc:685:10
    frame #17: 0x00000001000062ec magic_enum_protobuf_repro`_GLOBAL__I_000102 at example.pb.cc:0
    frame #18: 0x000000019b9daefc dyld`invocation function for block in dyld4::Loader::findAndRunAllInitializers(dyld4::RuntimeState&) const + 444
    frame #19: 0x000000019ba1789c dyld`invocation function for block in dyld3::MachOAnalyzer::forEachInitializer(Diagnostics&, dyld3::MachOAnalyzer::VMAddrConverter const&, void (unsigned int) block_pointer, void const*) const + 324
    frame #20: 0x000000019ba375cc dyld`invocation function for block in mach_o::Header::forEachSection(void (mach_o::Header::SectionInfo const&, bool&) block_pointer) const + 240
    frame #21: 0x000000019ba34358 dyld`mach_o::Header::forEachLoadCommand(void (load_command const*, bool&) block_pointer) const + 208
    frame #22: 0x000000019ba35a98 dyld`mach_o::Header::forEachSection(void (mach_o::Header::SectionInfo const&, bool&) block_pointer) const + 124
    frame #23: 0x000000019ba1736c dyld`dyld3::MachOAnalyzer::forEachInitializer(Diagnostics&, dyld3::MachOAnalyzer::VMAddrConverter const&, void (unsigned int) block_pointer, void const*) const + 516
    frame #24: 0x000000019b9dacb4 dyld`dyld4::Loader::findAndRunAllInitializers(dyld4::RuntimeState&) const + 176
    frame #25: 0x000000019b9e2670 dyld`dyld4::JustInTimeLoader::runInitializers(dyld4::RuntimeState&) const + 36
    frame #26: 0x000000019b9db460 dyld`dyld4::Loader::runInitializersBottomUp(dyld4::RuntimeState&, dyld3::Array<dyld4::Loader const*>&, dyld3::Array<dyld4::Loader const*>&) const + 308
    frame #27: 0x000000019b9dfbf0 dyld`dyld4::Loader::runInitializersBottomUpPlusUpwardLinks(dyld4::RuntimeState&) const::$_0::operator()() const + 180
    frame #28: 0x000000019b9db77c dyld`dyld4::Loader::runInitializersBottomUpPlusUpwardLinks(dyld4::RuntimeState&) const + 716
    frame #29: 0x000000019b9fca20 dyld`dyld4::APIs::runAllInitializersForMain() + 392
    frame #30: 0x000000019b9bfe00 dyld`dyld4::prepare(dyld4::APIs&, mach_o::Header const*) + 3092
    frame #31: 0x000000019b9bf1d8 dyld`dyld4::start(dyld4::KernelArgs*, void*, void*)::$_0::operator()() const + 236
    frame #32: 0x000000019b9beb4c dyld`start + 6000
(lldb) 
```