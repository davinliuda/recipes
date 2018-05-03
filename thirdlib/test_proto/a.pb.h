// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: a.proto

#ifndef PROTOBUF_a_2eproto__INCLUDED
#define PROTOBUF_a_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace ProtoCS {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_a_2eproto();
void protobuf_AssignDesc_a_2eproto();
void protobuf_ShutdownFile_a_2eproto();

class DD;
class Msg;
class MsgHead;

enum CmdID {
  CID_MOD = 1
};
bool CmdID_IsValid(int value);
const CmdID CmdID_MIN = CID_MOD;
const CmdID CmdID_MAX = CID_MOD;
const int CmdID_ARRAYSIZE = CmdID_MAX + 1;

const ::google::protobuf::EnumDescriptor* CmdID_descriptor();
inline const ::std::string& CmdID_Name(CmdID value) {
  return ::google::protobuf::internal::NameOfEnum(
    CmdID_descriptor(), value);
}
inline bool CmdID_Parse(
    const ::std::string& name, CmdID* value) {
  return ::google::protobuf::internal::ParseNamedEnum<CmdID>(
    CmdID_descriptor(), name, value);
}
// ===================================================================

class MsgHead : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoCS.MsgHead) */ {
 public:
  MsgHead();
  virtual ~MsgHead();

  MsgHead(const MsgHead& from);

  inline MsgHead& operator=(const MsgHead& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MsgHead& default_instance();

  void Swap(MsgHead* other);

  // implements Message ----------------------------------------------

  inline MsgHead* New() const { return New(NULL); }

  MsgHead* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MsgHead& from);
  void MergeFrom(const MsgHead& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(MsgHead* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 cid = 1;
  bool has_cid() const;
  void clear_cid();
  static const int kCidFieldNumber = 1;
  ::google::protobuf::int32 cid() const;
  void set_cid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:ProtoCS.MsgHead)
 private:
  inline void set_has_cid();
  inline void clear_has_cid();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 cid_;
  friend void  protobuf_AddDesc_a_2eproto();
  friend void protobuf_AssignDesc_a_2eproto();
  friend void protobuf_ShutdownFile_a_2eproto();

  void InitAsDefaultInstance();
  static MsgHead* default_instance_;
};
// -------------------------------------------------------------------

class Msg : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoCS.Msg) */ {
 public:
  Msg();
  virtual ~Msg();

  Msg(const Msg& from);

  inline Msg& operator=(const Msg& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Msg& default_instance();

  void Swap(Msg* other);

  // implements Message ----------------------------------------------

  inline Msg* New() const { return New(NULL); }

  Msg* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Msg& from);
  void MergeFrom(const Msg& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Msg* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .ProtoCS.MsgHead head = 1;
  bool has_head() const;
  void clear_head();
  static const int kHeadFieldNumber = 1;
  const ::ProtoCS::MsgHead& head() const;
  ::ProtoCS::MsgHead* mutable_head();
  ::ProtoCS::MsgHead* release_head();
  void set_allocated_head(::ProtoCS::MsgHead* head);

  // optional int32 ret_ret_ret = 2;
  bool has_ret_ret_ret() const;
  void clear_ret_ret_ret();
  static const int kRetRetRetFieldNumber = 2;
  ::google::protobuf::int32 ret_ret_ret() const;
  void set_ret_ret_ret(::google::protobuf::int32 value);

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(Msg)
  // @@protoc_insertion_point(class_scope:ProtoCS.Msg)
 private:
  inline void set_has_head();
  inline void clear_has_head();
  inline void set_has_ret_ret_ret();
  inline void clear_has_ret_ret_ret();

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::ProtoCS::MsgHead* head_;
  ::google::protobuf::int32 ret_ret_ret_;
  friend void  protobuf_AddDesc_a_2eproto();
  friend void protobuf_AssignDesc_a_2eproto();
  friend void protobuf_ShutdownFile_a_2eproto();

  void InitAsDefaultInstance();
  static Msg* default_instance_;
};
// -------------------------------------------------------------------

class DD : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:ProtoCS.DD) */ {
 public:
  DD();
  virtual ~DD();

  DD(const DD& from);

  inline DD& operator=(const DD& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DD& default_instance();

  void Swap(DD* other);

  // implements Message ----------------------------------------------

  inline DD* New() const { return New(NULL); }

  DD* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DD& from);
  void MergeFrom(const DD& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(DD* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  GOOGLE_PROTOBUF_EXTENSION_ACCESSORS(DD)
  // @@protoc_insertion_point(class_scope:ProtoCS.DD)
 private:

  ::google::protobuf::internal::ExtensionSet _extensions_;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_a_2eproto();
  friend void protobuf_AssignDesc_a_2eproto();
  friend void protobuf_ShutdownFile_a_2eproto();

  void InitAsDefaultInstance();
  static DD* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// MsgHead

// optional int32 cid = 1;
inline bool MsgHead::has_cid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MsgHead::set_has_cid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MsgHead::clear_has_cid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MsgHead::clear_cid() {
  cid_ = 0;
  clear_has_cid();
}
inline ::google::protobuf::int32 MsgHead::cid() const {
  // @@protoc_insertion_point(field_get:ProtoCS.MsgHead.cid)
  return cid_;
}
inline void MsgHead::set_cid(::google::protobuf::int32 value) {
  set_has_cid();
  cid_ = value;
  // @@protoc_insertion_point(field_set:ProtoCS.MsgHead.cid)
}

// -------------------------------------------------------------------

// Msg

// optional .ProtoCS.MsgHead head = 1;
inline bool Msg::has_head() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Msg::set_has_head() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Msg::clear_has_head() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Msg::clear_head() {
  if (head_ != NULL) head_->::ProtoCS::MsgHead::Clear();
  clear_has_head();
}
inline const ::ProtoCS::MsgHead& Msg::head() const {
  // @@protoc_insertion_point(field_get:ProtoCS.Msg.head)
  return head_ != NULL ? *head_ : *default_instance_->head_;
}
inline ::ProtoCS::MsgHead* Msg::mutable_head() {
  set_has_head();
  if (head_ == NULL) {
    head_ = new ::ProtoCS::MsgHead;
  }
  // @@protoc_insertion_point(field_mutable:ProtoCS.Msg.head)
  return head_;
}
inline ::ProtoCS::MsgHead* Msg::release_head() {
  // @@protoc_insertion_point(field_release:ProtoCS.Msg.head)
  clear_has_head();
  ::ProtoCS::MsgHead* temp = head_;
  head_ = NULL;
  return temp;
}
inline void Msg::set_allocated_head(::ProtoCS::MsgHead* head) {
  delete head_;
  head_ = head;
  if (head) {
    set_has_head();
  } else {
    clear_has_head();
  }
  // @@protoc_insertion_point(field_set_allocated:ProtoCS.Msg.head)
}

// optional int32 ret_ret_ret = 2;
inline bool Msg::has_ret_ret_ret() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Msg::set_has_ret_ret_ret() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Msg::clear_has_ret_ret_ret() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Msg::clear_ret_ret_ret() {
  ret_ret_ret_ = 0;
  clear_has_ret_ret_ret();
}
inline ::google::protobuf::int32 Msg::ret_ret_ret() const {
  // @@protoc_insertion_point(field_get:ProtoCS.Msg.ret_ret_ret)
  return ret_ret_ret_;
}
inline void Msg::set_ret_ret_ret(::google::protobuf::int32 value) {
  set_has_ret_ret_ret();
  ret_ret_ret_ = value;
  // @@protoc_insertion_point(field_set:ProtoCS.Msg.ret_ret_ret)
}

// -------------------------------------------------------------------

// DD

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ProtoCS

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::ProtoCS::CmdID> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ProtoCS::CmdID>() {
  return ::ProtoCS::CmdID_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_a_2eproto__INCLUDED
