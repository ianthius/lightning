/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: lightning.proto */

#ifndef PROTOBUF_C_lightning_2eproto__INCLUDED
#define PROTOBUF_C_lightning_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1001001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Sha256Hash Sha256Hash;
typedef struct _Signature Signature;
typedef struct _AnchorSpend AnchorSpend;
typedef struct _BitcoinPubkey BitcoinPubkey;
typedef struct _OpenChannel OpenChannel;
typedef struct _OpenAnchor OpenAnchor;
typedef struct _OpenEscapeSigs OpenEscapeSigs;
typedef struct _OpenCommitSig OpenCommitSig;
typedef struct _OpenComplete OpenComplete;
typedef struct _Update Update;
typedef struct _UpdateAccept UpdateAccept;
typedef struct _UpdateSignature UpdateSignature;
typedef struct _UpdateComplete UpdateComplete;
typedef struct _CloseChannel CloseChannel;
typedef struct _CloseChannelComplete CloseChannelComplete;
typedef struct _Error Error;
typedef struct _Pkt Pkt;


/* --- enums --- */


/* --- messages --- */

/*
 * Protobufs don't have fixed-length fields, so these are a hack.
 */
struct  _Sha256Hash
{
  ProtobufCMessage base;
  uint64_t a;
  uint64_t b;
  uint64_t c;
  uint64_t d;
};
#define SHA256_HASH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sha256_hash__descriptor) \
    , 0, 0, 0, 0 }


struct  _Signature
{
  ProtobufCMessage base;
  uint64_t r1;
  uint64_t r2;
  uint64_t r3;
  uint64_t r4;
  uint64_t s1;
  uint64_t s2;
  uint64_t s3;
  uint64_t s4;
};
#define SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&signature__descriptor) \
    , 0, 0, 0, 0, 0, 0, 0, 0 }


/*
 * To update the channel (commit tx or close tx) we need a signature for each
 * input.
 */
struct  _AnchorSpend
{
  ProtobufCMessage base;
  /*
   * From first anchor input.
   */
  Signature *sig0;
  /*
   * From second anchor input.
   */
  Signature *sig1;
};
#define ANCHOR_SPEND__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&anchor_spend__descriptor) \
    , NULL, NULL }


/*
 * Pubkey for commitment transaction input.
 */
struct  _BitcoinPubkey
{
  ProtobufCMessage base;
  /*
   * Either 65 or 33 bytes.
   */
  ProtobufCBinaryData key;
};
#define BITCOIN_PUBKEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&bitcoin_pubkey__descriptor) \
    , {0,NULL} }


typedef enum {
  OPEN_CHANNEL__LOCKTIME__NOT_SET = 0,
  OPEN_CHANNEL__LOCKTIME_LOCKTIME_SECONDS = 2,
  OPEN_CHANNEL__LOCKTIME_LOCKTIME_BLOCKS = 3,
} OpenChannel__LocktimeCase;

/*
 * Set channel params.
 */
struct  _OpenChannel
{
  ProtobufCMessage base;
  /*
   * Hash seed for revoking commitment transactions.
   */
  Sha256Hash *revocation_hash;
  /*
   * How to pay money to us from commit_tx (also for escape txs)
   */
  BitcoinPubkey *final;
  /*
   * How much transaction fee we'll pay for commitment txs.
   */
  uint64_t commitment_fee;
  /*
   * Key for commitment tx 2of2.
   */
  BitcoinPubkey *commitkey;
  /*
   * How much we'll be putting into channel
   */
  uint64_t total_input;
  /*
   * Secret hash for escape transactions.
   */
  Sha256Hash *escape_hash;
  /*
   * How many confirmations on anchor before we'll use channel.
   */
  uint32_t min_confirms;
  OpenChannel__LocktimeCase locktime_case;
  union {
    uint32_t locktime_seconds;
    uint32_t locktime_blocks;
  };
};
#define OPEN_CHANNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_channel__descriptor) \
    , NULL, NULL, 0, NULL, 0, NULL, 0, OPEN_CHANNEL__LOCKTIME__NOT_SET, {} }


/*
 * Give them the txid of our anchor transaction.
 */
struct  _OpenAnchor
{
  ProtobufCMessage base;
  Sha256Hash *anchor_txid;
  /*
   * Which output of anchor goes to this.
   */
  uint32_t index;
};
#define OPEN_ANCHOR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_anchor__descriptor) \
    , NULL, 0 }


/*
 * Give them signatures for their escape transactions.
 */
struct  _OpenEscapeSigs
{
  ProtobufCMessage base;
  /*
   * Signature for their escape tx.
   */
  Signature *escape;
  /*
   * Signature for their fast-escape tx.
   */
  Signature *fast_escape;
};
#define OPEN_ESCAPE_SIGS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_escape_sigs__descriptor) \
    , NULL, NULL }


/*
 * Supply signatures for commitment tx
 */
struct  _OpenCommitSig
{
  ProtobufCMessage base;
  AnchorSpend *sigs;
};
#define OPEN_COMMIT_SIG__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_commit_sig__descriptor) \
    , NULL }


/*
 * Indicates we've seen transaction reach min-depth.
 */
struct  _OpenComplete
{
  ProtobufCMessage base;
  /*
   * This invalidates my escape transaction.
   */
  Sha256Hash *escape_preimage;
};
#define OPEN_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&open_complete__descriptor) \
    , NULL }


/*
 * Let's spend some money in the channel!
 */
struct  _Update
{
  ProtobufCMessage base;
  /*
   * Hash for which I will supply preimage to revoke this.
   */
  Sha256Hash *revocation_hash;
  /*
   * Change in current payment to-me (implies reverse to-you).
   */
  /*
   * FIXME: optional HTLC ops.
   */
  int64_t delta;
};
#define UPDATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update__descriptor) \
    , NULL, 0 }


/*
 * OK, I accept that update; here's your signature.
 */
struct  _UpdateAccept
{
  ProtobufCMessage base;
  /*
   * Signatures for your new commitment tx.
   */
  AnchorSpend *sigs;
  /*
   * Hash for which I will supply preimage to revoke this new commit tx.
   */
  Sha256Hash *revocation_hash;
};
#define UPDATE_ACCEPT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_accept__descriptor) \
    , NULL, NULL }


/*
 * Thanks for accepting, here's my last bit.
 */
struct  _UpdateSignature
{
  ProtobufCMessage base;
  /*
   * Signatures for your new commitment tx.
   */
  AnchorSpend *sigs;
  /*
   * Hash preimage which revokes old commitment tx.
   */
  Sha256Hash *revocation_preimage;
};
#define UPDATE_SIGNATURE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_signature__descriptor) \
    , NULL, NULL }


/*
 * Complete the update.
 */
struct  _UpdateComplete
{
  ProtobufCMessage base;
  /*
   * Hash preimage which revokes old commitment tx.
   */
  Sha256Hash *revocation_preimage;
};
#define UPDATE_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&update_complete__descriptor) \
    , NULL }


/*
 * Begin cooperative close of channel.
 */
struct  _CloseChannel
{
  ProtobufCMessage base;
  /*
   * These are our signatures on a new transaction which spends the anchor
   * outputs to my open->final and your open->final, as per the last commit tx.
   */
  AnchorSpend *sigs;
};
#define CLOSE_CHANNEL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_channel__descriptor) \
    , NULL }


/*
 * OK, here's my sig so you can broadcast it too.  We're done.
 */
struct  _CloseChannelComplete
{
  ProtobufCMessage base;
  /*
   * These are my signatures for that same tx.
   */
  AnchorSpend *sigs;
};
#define CLOSE_CHANNEL_COMPLETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&close_channel_complete__descriptor) \
    , NULL }


/*
 * This means we're going to hang up; it's to help diagnose only! 
 */
struct  _Error
{
  ProtobufCMessage base;
  char *problem;
};
#define ERROR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&error__descriptor) \
    , NULL }


typedef enum {
  PKT__PKT__NOT_SET = 0,
  PKT__PKT_OPEN = 201,
  PKT__PKT_OPEN_ANCHOR = 203,
  PKT__PKT_OPEN_ESCAPE_SIGS = 205,
  PKT__PKT_OPEN_COMMIT_SIG = 202,
  PKT__PKT_OPEN_COMPLETE = 204,
  PKT__PKT_UPDATE = 1,
  PKT__PKT_UPDATE_ACCEPT = 2,
  PKT__PKT_UPDATE_SIGNATURE = 3,
  PKT__PKT_UPDATE_COMPLETE = 4,
  PKT__PKT_CLOSE = 401,
  PKT__PKT_CLOSE_COMPLETE = 402,
  PKT__PKT_ERROR = 1000,
} Pkt__PktCase;

/*
 * This is the union which defines all of them
 */
struct  _Pkt
{
  ProtobufCMessage base;
  Pkt__PktCase pkt_case;
  union {
    /*
     * Opening
     */
    OpenChannel *open;
    OpenAnchor *open_anchor;
    OpenEscapeSigs *open_escape_sigs;
    OpenCommitSig *open_commit_sig;
    OpenComplete *open_complete;
    /*
     * Updating (most common)
     */
    Update *update;
    UpdateAccept *update_accept;
    UpdateSignature *update_signature;
    UpdateComplete *update_complete;
    /*
     * Closing
     */
    CloseChannel *close;
    CloseChannelComplete *close_complete;
    /*
     * Unexpected issue.
     */
    Error *error;
  };
};
#define PKT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&pkt__descriptor) \
    , PKT__PKT__NOT_SET, {} }


/* Sha256Hash methods */
void   sha256_hash__init
                     (Sha256Hash         *message);
size_t sha256_hash__get_packed_size
                     (const Sha256Hash   *message);
size_t sha256_hash__pack
                     (const Sha256Hash   *message,
                      uint8_t             *out);
size_t sha256_hash__pack_to_buffer
                     (const Sha256Hash   *message,
                      ProtobufCBuffer     *buffer);
Sha256Hash *
       sha256_hash__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   sha256_hash__free_unpacked
                     (Sha256Hash *message,
                      ProtobufCAllocator *allocator);
/* Signature methods */
void   signature__init
                     (Signature         *message);
size_t signature__get_packed_size
                     (const Signature   *message);
size_t signature__pack
                     (const Signature   *message,
                      uint8_t             *out);
size_t signature__pack_to_buffer
                     (const Signature   *message,
                      ProtobufCBuffer     *buffer);
Signature *
       signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   signature__free_unpacked
                     (Signature *message,
                      ProtobufCAllocator *allocator);
/* AnchorSpend methods */
void   anchor_spend__init
                     (AnchorSpend         *message);
size_t anchor_spend__get_packed_size
                     (const AnchorSpend   *message);
size_t anchor_spend__pack
                     (const AnchorSpend   *message,
                      uint8_t             *out);
size_t anchor_spend__pack_to_buffer
                     (const AnchorSpend   *message,
                      ProtobufCBuffer     *buffer);
AnchorSpend *
       anchor_spend__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   anchor_spend__free_unpacked
                     (AnchorSpend *message,
                      ProtobufCAllocator *allocator);
/* BitcoinPubkey methods */
void   bitcoin_pubkey__init
                     (BitcoinPubkey         *message);
size_t bitcoin_pubkey__get_packed_size
                     (const BitcoinPubkey   *message);
size_t bitcoin_pubkey__pack
                     (const BitcoinPubkey   *message,
                      uint8_t             *out);
size_t bitcoin_pubkey__pack_to_buffer
                     (const BitcoinPubkey   *message,
                      ProtobufCBuffer     *buffer);
BitcoinPubkey *
       bitcoin_pubkey__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   bitcoin_pubkey__free_unpacked
                     (BitcoinPubkey *message,
                      ProtobufCAllocator *allocator);
/* OpenChannel methods */
void   open_channel__init
                     (OpenChannel         *message);
size_t open_channel__get_packed_size
                     (const OpenChannel   *message);
size_t open_channel__pack
                     (const OpenChannel   *message,
                      uint8_t             *out);
size_t open_channel__pack_to_buffer
                     (const OpenChannel   *message,
                      ProtobufCBuffer     *buffer);
OpenChannel *
       open_channel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_channel__free_unpacked
                     (OpenChannel *message,
                      ProtobufCAllocator *allocator);
/* OpenAnchor methods */
void   open_anchor__init
                     (OpenAnchor         *message);
size_t open_anchor__get_packed_size
                     (const OpenAnchor   *message);
size_t open_anchor__pack
                     (const OpenAnchor   *message,
                      uint8_t             *out);
size_t open_anchor__pack_to_buffer
                     (const OpenAnchor   *message,
                      ProtobufCBuffer     *buffer);
OpenAnchor *
       open_anchor__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_anchor__free_unpacked
                     (OpenAnchor *message,
                      ProtobufCAllocator *allocator);
/* OpenEscapeSigs methods */
void   open_escape_sigs__init
                     (OpenEscapeSigs         *message);
size_t open_escape_sigs__get_packed_size
                     (const OpenEscapeSigs   *message);
size_t open_escape_sigs__pack
                     (const OpenEscapeSigs   *message,
                      uint8_t             *out);
size_t open_escape_sigs__pack_to_buffer
                     (const OpenEscapeSigs   *message,
                      ProtobufCBuffer     *buffer);
OpenEscapeSigs *
       open_escape_sigs__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_escape_sigs__free_unpacked
                     (OpenEscapeSigs *message,
                      ProtobufCAllocator *allocator);
/* OpenCommitSig methods */
void   open_commit_sig__init
                     (OpenCommitSig         *message);
size_t open_commit_sig__get_packed_size
                     (const OpenCommitSig   *message);
size_t open_commit_sig__pack
                     (const OpenCommitSig   *message,
                      uint8_t             *out);
size_t open_commit_sig__pack_to_buffer
                     (const OpenCommitSig   *message,
                      ProtobufCBuffer     *buffer);
OpenCommitSig *
       open_commit_sig__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_commit_sig__free_unpacked
                     (OpenCommitSig *message,
                      ProtobufCAllocator *allocator);
/* OpenComplete methods */
void   open_complete__init
                     (OpenComplete         *message);
size_t open_complete__get_packed_size
                     (const OpenComplete   *message);
size_t open_complete__pack
                     (const OpenComplete   *message,
                      uint8_t             *out);
size_t open_complete__pack_to_buffer
                     (const OpenComplete   *message,
                      ProtobufCBuffer     *buffer);
OpenComplete *
       open_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   open_complete__free_unpacked
                     (OpenComplete *message,
                      ProtobufCAllocator *allocator);
/* Update methods */
void   update__init
                     (Update         *message);
size_t update__get_packed_size
                     (const Update   *message);
size_t update__pack
                     (const Update   *message,
                      uint8_t             *out);
size_t update__pack_to_buffer
                     (const Update   *message,
                      ProtobufCBuffer     *buffer);
Update *
       update__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update__free_unpacked
                     (Update *message,
                      ProtobufCAllocator *allocator);
/* UpdateAccept methods */
void   update_accept__init
                     (UpdateAccept         *message);
size_t update_accept__get_packed_size
                     (const UpdateAccept   *message);
size_t update_accept__pack
                     (const UpdateAccept   *message,
                      uint8_t             *out);
size_t update_accept__pack_to_buffer
                     (const UpdateAccept   *message,
                      ProtobufCBuffer     *buffer);
UpdateAccept *
       update_accept__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_accept__free_unpacked
                     (UpdateAccept *message,
                      ProtobufCAllocator *allocator);
/* UpdateSignature methods */
void   update_signature__init
                     (UpdateSignature         *message);
size_t update_signature__get_packed_size
                     (const UpdateSignature   *message);
size_t update_signature__pack
                     (const UpdateSignature   *message,
                      uint8_t             *out);
size_t update_signature__pack_to_buffer
                     (const UpdateSignature   *message,
                      ProtobufCBuffer     *buffer);
UpdateSignature *
       update_signature__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_signature__free_unpacked
                     (UpdateSignature *message,
                      ProtobufCAllocator *allocator);
/* UpdateComplete methods */
void   update_complete__init
                     (UpdateComplete         *message);
size_t update_complete__get_packed_size
                     (const UpdateComplete   *message);
size_t update_complete__pack
                     (const UpdateComplete   *message,
                      uint8_t             *out);
size_t update_complete__pack_to_buffer
                     (const UpdateComplete   *message,
                      ProtobufCBuffer     *buffer);
UpdateComplete *
       update_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   update_complete__free_unpacked
                     (UpdateComplete *message,
                      ProtobufCAllocator *allocator);
/* CloseChannel methods */
void   close_channel__init
                     (CloseChannel         *message);
size_t close_channel__get_packed_size
                     (const CloseChannel   *message);
size_t close_channel__pack
                     (const CloseChannel   *message,
                      uint8_t             *out);
size_t close_channel__pack_to_buffer
                     (const CloseChannel   *message,
                      ProtobufCBuffer     *buffer);
CloseChannel *
       close_channel__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_channel__free_unpacked
                     (CloseChannel *message,
                      ProtobufCAllocator *allocator);
/* CloseChannelComplete methods */
void   close_channel_complete__init
                     (CloseChannelComplete         *message);
size_t close_channel_complete__get_packed_size
                     (const CloseChannelComplete   *message);
size_t close_channel_complete__pack
                     (const CloseChannelComplete   *message,
                      uint8_t             *out);
size_t close_channel_complete__pack_to_buffer
                     (const CloseChannelComplete   *message,
                      ProtobufCBuffer     *buffer);
CloseChannelComplete *
       close_channel_complete__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   close_channel_complete__free_unpacked
                     (CloseChannelComplete *message,
                      ProtobufCAllocator *allocator);
/* Error methods */
void   error__init
                     (Error         *message);
size_t error__get_packed_size
                     (const Error   *message);
size_t error__pack
                     (const Error   *message,
                      uint8_t             *out);
size_t error__pack_to_buffer
                     (const Error   *message,
                      ProtobufCBuffer     *buffer);
Error *
       error__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   error__free_unpacked
                     (Error *message,
                      ProtobufCAllocator *allocator);
/* Pkt methods */
void   pkt__init
                     (Pkt         *message);
size_t pkt__get_packed_size
                     (const Pkt   *message);
size_t pkt__pack
                     (const Pkt   *message,
                      uint8_t             *out);
size_t pkt__pack_to_buffer
                     (const Pkt   *message,
                      ProtobufCBuffer     *buffer);
Pkt *
       pkt__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   pkt__free_unpacked
                     (Pkt *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Sha256Hash_Closure)
                 (const Sha256Hash *message,
                  void *closure_data);
typedef void (*Signature_Closure)
                 (const Signature *message,
                  void *closure_data);
typedef void (*AnchorSpend_Closure)
                 (const AnchorSpend *message,
                  void *closure_data);
typedef void (*BitcoinPubkey_Closure)
                 (const BitcoinPubkey *message,
                  void *closure_data);
typedef void (*OpenChannel_Closure)
                 (const OpenChannel *message,
                  void *closure_data);
typedef void (*OpenAnchor_Closure)
                 (const OpenAnchor *message,
                  void *closure_data);
typedef void (*OpenEscapeSigs_Closure)
                 (const OpenEscapeSigs *message,
                  void *closure_data);
typedef void (*OpenCommitSig_Closure)
                 (const OpenCommitSig *message,
                  void *closure_data);
typedef void (*OpenComplete_Closure)
                 (const OpenComplete *message,
                  void *closure_data);
typedef void (*Update_Closure)
                 (const Update *message,
                  void *closure_data);
typedef void (*UpdateAccept_Closure)
                 (const UpdateAccept *message,
                  void *closure_data);
typedef void (*UpdateSignature_Closure)
                 (const UpdateSignature *message,
                  void *closure_data);
typedef void (*UpdateComplete_Closure)
                 (const UpdateComplete *message,
                  void *closure_data);
typedef void (*CloseChannel_Closure)
                 (const CloseChannel *message,
                  void *closure_data);
typedef void (*CloseChannelComplete_Closure)
                 (const CloseChannelComplete *message,
                  void *closure_data);
typedef void (*Error_Closure)
                 (const Error *message,
                  void *closure_data);
typedef void (*Pkt_Closure)
                 (const Pkt *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor sha256_hash__descriptor;
extern const ProtobufCMessageDescriptor signature__descriptor;
extern const ProtobufCMessageDescriptor anchor_spend__descriptor;
extern const ProtobufCMessageDescriptor bitcoin_pubkey__descriptor;
extern const ProtobufCMessageDescriptor open_channel__descriptor;
extern const ProtobufCMessageDescriptor open_anchor__descriptor;
extern const ProtobufCMessageDescriptor open_escape_sigs__descriptor;
extern const ProtobufCMessageDescriptor open_commit_sig__descriptor;
extern const ProtobufCMessageDescriptor open_complete__descriptor;
extern const ProtobufCMessageDescriptor update__descriptor;
extern const ProtobufCMessageDescriptor update_accept__descriptor;
extern const ProtobufCMessageDescriptor update_signature__descriptor;
extern const ProtobufCMessageDescriptor update_complete__descriptor;
extern const ProtobufCMessageDescriptor close_channel__descriptor;
extern const ProtobufCMessageDescriptor close_channel_complete__descriptor;
extern const ProtobufCMessageDescriptor error__descriptor;
extern const ProtobufCMessageDescriptor pkt__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_lightning_2eproto__INCLUDED */
