// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: b.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "b.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace ProtoCS {

namespace {

const ::google::protobuf::Descriptor* ModReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ModReq_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_b_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_b_2eproto() {
  protobuf_AddDesc_b_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "b.proto");
  GOOGLE_CHECK(file != NULL);
  ModReq_descriptor_ = file->message_type(0);
  static const int ModReq_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModReq, b_),
  };
  ModReq_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ModReq_descriptor_,
      ModReq::default_instance_,
      ModReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModReq, _has_bits_[0]),
      -1,
      -1,
      sizeof(ModReq),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ModReq, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_b_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ModReq_descriptor_, &ModReq::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_b_2eproto() {
  delete ModReq::default_instance_;
  delete ModReq_reflection_;
}

void protobuf_AddDesc_b_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_b_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::ProtoCS::protobuf_AddDesc_a_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\007b.proto\022\007ProtoCS\032\007a.proto\"\023\n\006ModReq\022\t\n"
    "\001b\030\001 \001(\010:\030\n\002id\022\014.ProtoCS.Msg\030~ \001(\005:.\n\007mo"
    "d_req\022\014.ProtoCS.Msg\030\177 \001(\0132\017.ProtoCS.ModR"
    "eq:\030\n\003id1\022\013.ProtoCS.DD\030~ \001(\005", 148);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "b.proto", &protobuf_RegisterTypes);
  ModReq::default_instance_ = new ModReq();
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::ProtoCS::Msg::default_instance(),
    126, 5, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterMessageExtension(
    &::ProtoCS::Msg::default_instance(),
    127, 11, false, false,
    &::ProtoCS::ModReq::default_instance());
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::ProtoCS::DD::default_instance(),
    126, 5, false, false);
  ModReq::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_b_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_b_2eproto {
  StaticDescriptorInitializer_b_2eproto() {
    protobuf_AddDesc_b_2eproto();
  }
} static_descriptor_initializer_b_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ModReq::kBFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ModReq::ModReq()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:ProtoCS.ModReq)
}

void ModReq::InitAsDefaultInstance() {
}

ModReq::ModReq(const ModReq& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:ProtoCS.ModReq)
}

void ModReq::SharedCtor() {
  _cached_size_ = 0;
  b_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ModReq::~ModReq() {
  // @@protoc_insertion_point(destructor:ProtoCS.ModReq)
  SharedDtor();
}

void ModReq::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ModReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ModReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ModReq_descriptor_;
}

const ModReq& ModReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_b_2eproto();
  return *default_instance_;
}

ModReq* ModReq::default_instance_ = NULL;

ModReq* ModReq::New(::google::protobuf::Arena* arena) const {
  ModReq* n = new ModReq;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ModReq::Clear() {
// @@protoc_insertion_point(message_clear_start:ProtoCS.ModReq)
  b_ = false;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool ModReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:ProtoCS.ModReq)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool b = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &b_)));
          set_has_b();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:ProtoCS.ModReq)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:ProtoCS.ModReq)
  return false;
#undef DO_
}

void ModReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:ProtoCS.ModReq)
  // optional bool b = 1;
  if (has_b()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->b(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:ProtoCS.ModReq)
}

::google::protobuf::uint8* ModReq::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:ProtoCS.ModReq)
  // optional bool b = 1;
  if (has_b()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->b(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ProtoCS.ModReq)
  return target;
}

int ModReq::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:ProtoCS.ModReq)
  int total_size = 0;

  // optional bool b = 1;
  if (has_b()) {
    total_size += 1 + 1;
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ModReq::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:ProtoCS.ModReq)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const ModReq* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ModReq>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:ProtoCS.ModReq)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:ProtoCS.ModReq)
    MergeFrom(*source);
  }
}

void ModReq::MergeFrom(const ModReq& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:ProtoCS.ModReq)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_b()) {
      set_b(from.b());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void ModReq::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:ProtoCS.ModReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ModReq::CopyFrom(const ModReq& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ProtoCS.ModReq)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModReq::IsInitialized() const {

  return true;
}

void ModReq::Swap(ModReq* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ModReq::InternalSwap(ModReq* other) {
  std::swap(b_, other->b_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ModReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ModReq_descriptor_;
  metadata.reflection = ModReq_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ModReq

// optional bool b = 1;
bool ModReq::has_b() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void ModReq::set_has_b() {
  _has_bits_[0] |= 0x00000001u;
}
void ModReq::clear_has_b() {
  _has_bits_[0] &= ~0x00000001u;
}
void ModReq::clear_b() {
  b_ = false;
  clear_has_b();
}
 bool ModReq::b() const {
  // @@protoc_insertion_point(field_get:ProtoCS.ModReq.b)
  return b_;
}
 void ModReq::set_b(bool value) {
  set_has_b();
  b_ = value;
  // @@protoc_insertion_point(field_set:ProtoCS.ModReq.b)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS
::google::protobuf::internal::ExtensionIdentifier< ::ProtoCS::Msg,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
  id(kIdFieldNumber, 0);
::google::protobuf::internal::ExtensionIdentifier< ::ProtoCS::Msg,
    ::google::protobuf::internal::MessageTypeTraits< ::ProtoCS::ModReq >, 11, false >
  mod_req(kModReqFieldNumber, ::ProtoCS::ModReq::default_instance());
::google::protobuf::internal::ExtensionIdentifier< ::ProtoCS::DD,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
  id1(kId1FieldNumber, 0);

// @@protoc_insertion_point(namespace_scope)

}  // namespace ProtoCS

// @@protoc_insertion_point(global_scope)
