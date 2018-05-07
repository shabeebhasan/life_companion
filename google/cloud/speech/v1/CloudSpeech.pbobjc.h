// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/cloud/speech/v1/cloud_speech.proto

// This CPP symbol can be defined to use imports that match up to the framework
// imports needed when using CocoaPods.
#if !defined(GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS)
 #define GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS 0
#endif

#if GPB_USE_PROTOBUF_FRAMEWORK_IMPORTS
 #import <Protobuf/GPBProtocolBuffers.h>
#else
 #import "GPBProtocolBuffers.h"
#endif

#if GOOGLE_PROTOBUF_OBJC_GEN_VERSION != 30001
#error This file was generated by a different version of protoc which is incompatible with your Protocol Buffer library sources.
#endif

// @@protoc_insertion_point(imports)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

CF_EXTERN_C_BEGIN

@class GPBTimestamp;
@class RecognitionAudio;
@class RecognitionConfig;
@class SpeechContext;
@class SpeechRecognitionAlternative;
@class SpeechRecognitionResult;
@class Status;
@class StreamingRecognitionConfig;
@class StreamingRecognitionResult;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Enum RecognitionConfig_AudioEncoding

/**
 * Audio encoding of the data sent in the audio message. All encodings support
 * only 1 channel (mono) audio. Only `FLAC` includes a header that describes
 * the bytes of audio that follow the header. The other encodings are raw
 * audio bytes with no header.
 *
 * For best results, the audio source should be captured and transmitted using
 * a lossless encoding (`FLAC` or `LINEAR16`). Recognition accuracy may be
 * reduced if lossy codecs, which include the other codecs listed in
 * this section, are used to capture or transmit the audio, particularly if
 * background noise is present.
 **/
typedef GPB_ENUM(RecognitionConfig_AudioEncoding) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  RecognitionConfig_AudioEncoding_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /** Not specified. Will return result [google.rpc.Code.INVALID_ARGUMENT][]. */
  RecognitionConfig_AudioEncoding_EncodingUnspecified = 0,

  /** Uncompressed 16-bit signed little-endian samples (Linear PCM). */
  RecognitionConfig_AudioEncoding_Linear16 = 1,

  /**
   * [`FLAC`](https://xiph.org/flac/documentation.html) (Free Lossless Audio
   * Codec) is the recommended encoding because it is
   * lossless--therefore recognition is not compromised--and
   * requires only about half the bandwidth of `LINEAR16`. `FLAC` stream
   * encoding supports 16-bit and 24-bit samples, however, not all fields in
   * `STREAMINFO` are supported.
   **/
  RecognitionConfig_AudioEncoding_Flac = 2,

  /** 8-bit samples that compand 14-bit audio samples using G.711 PCMU/mu-law. */
  RecognitionConfig_AudioEncoding_Mulaw = 3,

  /** Adaptive Multi-Rate Narrowband codec. `sample_rate_hertz` must be 8000. */
  RecognitionConfig_AudioEncoding_Amr = 4,

  /** Adaptive Multi-Rate Wideband codec. `sample_rate_hertz` must be 16000. */
  RecognitionConfig_AudioEncoding_AmrWb = 5,

  /**
   * Opus encoded audio frames in Ogg container
   * ([OggOpus](https://wiki.xiph.org/OggOpus)).
   * `sample_rate_hertz` must be 16000.
   **/
  RecognitionConfig_AudioEncoding_OggOpus = 6,

  /**
   * Although the use of lossy encodings is not recommended, if a very low
   * bitrate encoding is required, `OGG_OPUS` is highly preferred over
   * Speex encoding. The [Speex](https://speex.org/)  encoding supported by
   * Cloud Speech API has a header byte in each block, as in MIME type
   * `audio/x-speex-with-header-byte`.
   * It is a variant of the RTP Speex encoding defined in
   * [RFC 5574](https://tools.ietf.org/html/rfc5574).
   * The stream is a sequence of blocks, one block per RTP packet. Each block
   * starts with a byte containing the length of the block, in bytes, followed
   * by one or more frames of Speex data, padded to an integral number of
   * bytes (octets) as specified in RFC 5574. In other words, each RTP header
   * is replaced with a single byte containing the block length. Only Speex
   * wideband is supported. `sample_rate_hertz` must be 16000.
   **/
  RecognitionConfig_AudioEncoding_SpeexWithHeaderByte = 7,
};

GPBEnumDescriptor *RecognitionConfig_AudioEncoding_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL RecognitionConfig_AudioEncoding_IsValidValue(int32_t value);

#pragma mark - Enum StreamingRecognizeResponse_SpeechEventType

/** Indicates the type of speech event. */
typedef GPB_ENUM(StreamingRecognizeResponse_SpeechEventType) {
  /**
   * Value used if any message's field encounters a value that is not defined
   * by this enum. The message will also have C functions to get/set the rawValue
   * of the field.
   **/
  StreamingRecognizeResponse_SpeechEventType_GPBUnrecognizedEnumeratorValue = kGPBUnrecognizedEnumeratorValue,
  /** No speech event specified. */
  StreamingRecognizeResponse_SpeechEventType_SpeechEventUnspecified = 0,

  /**
   * This event indicates that the server has detected the end of the user's
   * speech utterance and expects no additional speech. Therefore, the server
   * will not process additional audio (although it may subsequently return
   * additional results). The client should stop sending additional audio
   * data, half-close the gRPC connection, and wait for any additional results
   * until the server closes the gRPC connection. This event is only sent if
   * `single_utterance` was set to `true`, and is not used otherwise.
   **/
  StreamingRecognizeResponse_SpeechEventType_EndOfSingleUtterance = 1,
};

GPBEnumDescriptor *StreamingRecognizeResponse_SpeechEventType_EnumDescriptor(void);

/**
 * Checks to see if the given value is defined by the enum or was not known at
 * the time this source was generated.
 **/
BOOL StreamingRecognizeResponse_SpeechEventType_IsValidValue(int32_t value);

#pragma mark - CloudSpeechRoot

/**
 * Exposes the extension registry for this file.
 *
 * The base class provides:
 * @code
 *   + (GPBExtensionRegistry *)extensionRegistry;
 * @endcode
 * which is a @c GPBExtensionRegistry that includes all the extensions defined by
 * this file and all files that it depends on.
 **/
@interface CloudSpeechRoot : GPBRootObject
@end

#pragma mark - RecognizeRequest

typedef GPB_ENUM(RecognizeRequest_FieldNumber) {
  RecognizeRequest_FieldNumber_Config = 1,
  RecognizeRequest_FieldNumber_Audio = 2,
};

/**
 * The top-level message sent by the client for the `Recognize` method.
 **/
@interface RecognizeRequest : GPBMessage

/**
 * *Required* Provides information to the recognizer that specifies how to
 * process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/** *Required* The audio data to be recognized. */
@property(nonatomic, readwrite, strong, null_resettable) RecognitionAudio *audio;
/** Test to see if @c audio has been set. */
@property(nonatomic, readwrite) BOOL hasAudio;

@end

#pragma mark - LongRunningRecognizeRequest

typedef GPB_ENUM(LongRunningRecognizeRequest_FieldNumber) {
  LongRunningRecognizeRequest_FieldNumber_Config = 1,
  LongRunningRecognizeRequest_FieldNumber_Audio = 2,
};

/**
 * The top-level message sent by the client for the `LongRunningRecognize`
 * method.
 **/
@interface LongRunningRecognizeRequest : GPBMessage

/**
 * *Required* Provides information to the recognizer that specifies how to
 * process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/** *Required* The audio data to be recognized. */
@property(nonatomic, readwrite, strong, null_resettable) RecognitionAudio *audio;
/** Test to see if @c audio has been set. */
@property(nonatomic, readwrite) BOOL hasAudio;

@end

#pragma mark - StreamingRecognizeRequest

typedef GPB_ENUM(StreamingRecognizeRequest_FieldNumber) {
  StreamingRecognizeRequest_FieldNumber_StreamingConfig = 1,
  StreamingRecognizeRequest_FieldNumber_AudioContent = 2,
};

typedef GPB_ENUM(StreamingRecognizeRequest_StreamingRequest_OneOfCase) {
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_GPBUnsetOneOfCase = 0,
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_StreamingConfig = 1,
  StreamingRecognizeRequest_StreamingRequest_OneOfCase_AudioContent = 2,
};

/**
 * The top-level message sent by the client for the `StreamingRecognize` method.
 * Multiple `StreamingRecognizeRequest` messages are sent. The first message
 * must contain a `streaming_config` message and must not contain `audio` data.
 * All subsequent messages must contain `audio` data and must not contain a
 * `streaming_config` message.
 **/
@interface StreamingRecognizeRequest : GPBMessage

@property(nonatomic, readonly) StreamingRecognizeRequest_StreamingRequest_OneOfCase streamingRequestOneOfCase;

/**
 * Provides information to the recognizer that specifies how to process the
 * request. The first `StreamingRecognizeRequest` message must contain a
 * `streaming_config`  message.
 **/
@property(nonatomic, readwrite, strong, null_resettable) StreamingRecognitionConfig *streamingConfig;

/**
 * The audio data to be recognized. Sequential chunks of audio data are sent
 * in sequential `StreamingRecognizeRequest` messages. The first
 * `StreamingRecognizeRequest` message must not contain `audio_content` data
 * and all subsequent `StreamingRecognizeRequest` messages must contain
 * `audio_content` data. The audio bytes must be encoded as specified in
 * `RecognitionConfig`. Note: as with all bytes fields, protobuffers use a
 * pure binary representation (not base64). See
 * [audio limits](https://cloud.google.com/speech/limits#content).
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSData *audioContent;

@end

/**
 * Clears whatever value was set for the oneof 'streamingRequest'.
 **/
void StreamingRecognizeRequest_ClearStreamingRequestOneOfCase(StreamingRecognizeRequest *message);

#pragma mark - StreamingRecognitionConfig

typedef GPB_ENUM(StreamingRecognitionConfig_FieldNumber) {
  StreamingRecognitionConfig_FieldNumber_Config = 1,
  StreamingRecognitionConfig_FieldNumber_SingleUtterance = 2,
  StreamingRecognitionConfig_FieldNumber_InterimResults = 3,
};

/**
 * Provides information to the recognizer that specifies how to process the
 * request.
 **/
@interface StreamingRecognitionConfig : GPBMessage

/**
 * *Required* Provides information to the recognizer that specifies how to
 * process the request.
 **/
@property(nonatomic, readwrite, strong, null_resettable) RecognitionConfig *config;
/** Test to see if @c config has been set. */
@property(nonatomic, readwrite) BOOL hasConfig;

/**
 * *Optional* If `false` or omitted, the recognizer will perform continuous
 * recognition (continuing to wait for and process audio even if the user
 * pauses speaking) until the client closes the input stream (gRPC API) or
 * until the maximum time limit has been reached. May return multiple
 * `StreamingRecognitionResult`s with the `is_final` flag set to `true`.
 *
 * If `true`, the recognizer will detect a single spoken utterance. When it
 * detects that the user has paused or stopped speaking, it will return an
 * `END_OF_SINGLE_UTTERANCE` event and cease recognition. It will return no
 * more than one `StreamingRecognitionResult` with the `is_final` flag set to
 * `true`.
 **/
@property(nonatomic, readwrite) BOOL singleUtterance;

/**
 * *Optional* If `true`, interim results (tentative hypotheses) may be
 * returned as they become available (these interim results are indicated with
 * the `is_final=false` flag).
 * If `false` or omitted, only `is_final=true` result(s) are returned.
 **/
@property(nonatomic, readwrite) BOOL interimResults;

@end

#pragma mark - RecognitionConfig

typedef GPB_ENUM(RecognitionConfig_FieldNumber) {
  RecognitionConfig_FieldNumber_Encoding = 1,
  RecognitionConfig_FieldNumber_SampleRateHertz = 2,
  RecognitionConfig_FieldNumber_LanguageCode = 3,
  RecognitionConfig_FieldNumber_MaxAlternatives = 4,
  RecognitionConfig_FieldNumber_ProfanityFilter = 5,
  RecognitionConfig_FieldNumber_SpeechContextsArray = 6,
};

/**
 * Provides information to the recognizer that specifies how to process the
 * request.
 **/
@interface RecognitionConfig : GPBMessage

/** *Required* Encoding of audio data sent in all `RecognitionAudio` messages. */
@property(nonatomic, readwrite) RecognitionConfig_AudioEncoding encoding;

/**
 * *Required* Sample rate in Hertz of the audio data sent in all
 * `RecognitionAudio` messages. Valid values are: 8000-48000.
 * 16000 is optimal. For best results, set the sampling rate of the audio
 * source to 16000 Hz. If that's not possible, use the native sample rate of
 * the audio source (instead of re-sampling).
 **/
@property(nonatomic, readwrite) int32_t sampleRateHertz;

/**
 * *Required* The language of the supplied audio as a
 * [BCP-47](https://www.rfc-editor.org/rfc/bcp/bcp47.txt) language tag.
 * Example: "en-US".
 * See [Language Support](https://cloud.google.com/speech/docs/languages)
 * for a list of the currently supported language codes.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *languageCode;

/**
 * *Optional* Maximum number of recognition hypotheses to be returned.
 * Specifically, the maximum number of `SpeechRecognitionAlternative` messages
 * within each `SpeechRecognitionResult`.
 * The server may return fewer than `max_alternatives`.
 * Valid values are `0`-`30`. A value of `0` or `1` will return a maximum of
 * one. If omitted, will return a maximum of one.
 **/
@property(nonatomic, readwrite) int32_t maxAlternatives;

/**
 * *Optional* If set to `true`, the server will attempt to filter out
 * profanities, replacing all but the initial character in each filtered word
 * with asterisks, e.g. "f***". If set to `false` or omitted, profanities
 * won't be filtered out.
 **/
@property(nonatomic, readwrite) BOOL profanityFilter;

/** *Optional* A means to provide context to assist the speech recognition. */
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechContext*> *speechContextsArray;
/** The number of items in @c speechContextsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger speechContextsArray_Count;

@end

/**
 * Fetches the raw value of a @c RecognitionConfig's @c encoding property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t RecognitionConfig_Encoding_RawValue(RecognitionConfig *message);
/**
 * Sets the raw value of an @c RecognitionConfig's @c encoding property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetRecognitionConfig_Encoding_RawValue(RecognitionConfig *message, int32_t value);

#pragma mark - SpeechContext

typedef GPB_ENUM(SpeechContext_FieldNumber) {
  SpeechContext_FieldNumber_PhrasesArray = 1,
};

/**
 * Provides "hints" to the speech recognizer to favor specific words and phrases
 * in the results.
 **/
@interface SpeechContext : GPBMessage

/**
 * *Optional* A list of strings containing words and phrases "hints" so that
 * the speech recognition is more likely to recognize them. This can be used
 * to improve the accuracy for specific words and phrases, for example, if
 * specific commands are typically spoken by the user. This can also be used
 * to add additional words to the vocabulary of the recognizer. See
 * [usage limits](https://cloud.google.com/speech/limits#content).
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<NSString*> *phrasesArray;
/** The number of items in @c phrasesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger phrasesArray_Count;

@end

#pragma mark - RecognitionAudio

typedef GPB_ENUM(RecognitionAudio_FieldNumber) {
  RecognitionAudio_FieldNumber_Content = 1,
  RecognitionAudio_FieldNumber_Uri = 2,
};

typedef GPB_ENUM(RecognitionAudio_AudioSource_OneOfCase) {
  RecognitionAudio_AudioSource_OneOfCase_GPBUnsetOneOfCase = 0,
  RecognitionAudio_AudioSource_OneOfCase_Content = 1,
  RecognitionAudio_AudioSource_OneOfCase_Uri = 2,
};

/**
 * Contains audio data in the encoding specified in the `RecognitionConfig`.
 * Either `content` or `uri` must be supplied. Supplying both or neither
 * returns [google.rpc.Code.INVALID_ARGUMENT][]. See
 * [audio limits](https://cloud.google.com/speech/limits#content).
 **/
@interface RecognitionAudio : GPBMessage

@property(nonatomic, readonly) RecognitionAudio_AudioSource_OneOfCase audioSourceOneOfCase;

/**
 * The audio data bytes encoded as specified in
 * `RecognitionConfig`. Note: as with all bytes fields, protobuffers use a
 * pure binary representation, whereas JSON representations use base64.
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSData *content;

/**
 * URI that points to a file that contains audio data bytes as specified in
 * `RecognitionConfig`. Currently, only Google Cloud Storage URIs are
 * supported, which must be specified in the following format:
 * `gs://bucket_name/object_name` (other URI formats return
 * [google.rpc.Code.INVALID_ARGUMENT][]). For more information, see
 * [Request URIs](https://cloud.google.com/storage/docs/reference-uris).
 **/
@property(nonatomic, readwrite, copy, null_resettable) NSString *uri;

@end

/**
 * Clears whatever value was set for the oneof 'audioSource'.
 **/
void RecognitionAudio_ClearAudioSourceOneOfCase(RecognitionAudio *message);

#pragma mark - RecognizeResponse

typedef GPB_ENUM(RecognizeResponse_FieldNumber) {
  RecognizeResponse_FieldNumber_ResultsArray = 2,
};

/**
 * The only message returned to the client by the `Recognize` method. It
 * contains the result as zero or more sequential `SpeechRecognitionResult`
 * messages.
 **/
@interface RecognizeResponse : GPBMessage

/**
 * *Output-only* Sequential list of transcription results corresponding to
 * sequential portions of audio.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

@end

#pragma mark - LongRunningRecognizeResponse

typedef GPB_ENUM(LongRunningRecognizeResponse_FieldNumber) {
  LongRunningRecognizeResponse_FieldNumber_ResultsArray = 2,
};

/**
 * The only message returned to the client by the `LongRunningRecognize` method.
 * It contains the result as zero or more sequential `SpeechRecognitionResult`
 * messages. It is included in the `result.response` field of the `Operation`
 * returned by the `GetOperation` call of the `google::longrunning::Operations`
 * service.
 **/
@interface LongRunningRecognizeResponse : GPBMessage

/**
 * *Output-only* Sequential list of transcription results corresponding to
 * sequential portions of audio.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

@end

#pragma mark - LongRunningRecognizeMetadata

typedef GPB_ENUM(LongRunningRecognizeMetadata_FieldNumber) {
  LongRunningRecognizeMetadata_FieldNumber_ProgressPercent = 1,
  LongRunningRecognizeMetadata_FieldNumber_StartTime = 2,
  LongRunningRecognizeMetadata_FieldNumber_LastUpdateTime = 3,
};

/**
 * Describes the progress of a long-running `LongRunningRecognize` call. It is
 * included in the `metadata` field of the `Operation` returned by the
 * `GetOperation` call of the `google::longrunning::Operations` service.
 **/
@interface LongRunningRecognizeMetadata : GPBMessage

/**
 * Approximate percentage of audio processed thus far. Guaranteed to be 100
 * when the audio is fully processed and the results are available.
 **/
@property(nonatomic, readwrite) int32_t progressPercent;

/** Time when the request was received. */
@property(nonatomic, readwrite, strong, null_resettable) GPBTimestamp *startTime;
/** Test to see if @c startTime has been set. */
@property(nonatomic, readwrite) BOOL hasStartTime;

/** Time of the most recent processing update. */
@property(nonatomic, readwrite, strong, null_resettable) GPBTimestamp *lastUpdateTime;
/** Test to see if @c lastUpdateTime has been set. */
@property(nonatomic, readwrite) BOOL hasLastUpdateTime;

@end

#pragma mark - StreamingRecognizeResponse

typedef GPB_ENUM(StreamingRecognizeResponse_FieldNumber) {
  StreamingRecognizeResponse_FieldNumber_Error = 1,
  StreamingRecognizeResponse_FieldNumber_ResultsArray = 2,
  StreamingRecognizeResponse_FieldNumber_SpeechEventType = 4,
};

/**
 * `StreamingRecognizeResponse` is the only message returned to the client by
 * `StreamingRecognize`. A series of one or more `StreamingRecognizeResponse`
 * messages are streamed back to the client.
 *
 * Here's an example of a series of ten `StreamingRecognizeResponse`s that might
 * be returned while processing audio:
 *
 * 1. results { alternatives { transcript: "tube" } stability: 0.01 }
 *
 * 2. results { alternatives { transcript: "to be a" } stability: 0.01 }
 *
 * 3. results { alternatives { transcript: "to be" } stability: 0.9 }
 *    results { alternatives { transcript: " or not to be" } stability: 0.01 }
 *
 * 4. results { alternatives { transcript: "to be or not to be"
 *                             confidence: 0.92 }
 *              alternatives { transcript: "to bee or not to bee" }
 *              is_final: true }
 *
 * 5. results { alternatives { transcript: " that's" } stability: 0.01 }
 *
 * 6. results { alternatives { transcript: " that is" } stability: 0.9 }
 *    results { alternatives { transcript: " the question" } stability: 0.01 }
 *
 * 7. speech_event_type: END_OF_SINGLE_UTTERANCE
 *
 * 8. results { alternatives { transcript: " that is the question"
 *                             confidence: 0.98 }
 *              alternatives { transcript: " that was the question" }
 *              is_final: true }
 *
 * Notes:
 *
 * - Only two of the above responses #4 and #8 contain final results; they are
 *   indicated by `is_final: true`. Concatenating these together generates the
 *   full transcript: "to be or not to be that is the question".
 *
 * - The others contain interim `results`. #3 and #6 contain two interim
 *   `results`: the first portion has a high stability and is less likely to
 *   change; the second portion has a low stability and is very likely to
 *   change. A UI designer might choose to show only high stability `results`.
 *
 * - The specific `stability` and `confidence` values shown above are only for
 *   illustrative purposes. Actual values may vary.
 *
 * - In each response, only one of these fields will be set:
 *     `error`,
 *     `speech_event_type`, or
 *     one or more (repeated) `results`.
 **/
@interface StreamingRecognizeResponse : GPBMessage

/**
 * *Output-only* If set, returns a [google.rpc.Status][] message that
 * specifies the error for the operation.
 **/
@property(nonatomic, readwrite, strong, null_resettable) Status *error;
/** Test to see if @c error has been set. */
@property(nonatomic, readwrite) BOOL hasError;

/**
 * *Output-only* This repeated list contains zero or more results that
 * correspond to consecutive portions of the audio currently being processed.
 * It contains zero or one `is_final=true` result (the newly settled portion),
 * followed by zero or more `is_final=false` results.
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<StreamingRecognitionResult*> *resultsArray;
/** The number of items in @c resultsArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger resultsArray_Count;

/** *Output-only* Indicates the type of speech event. */
@property(nonatomic, readwrite) StreamingRecognizeResponse_SpeechEventType speechEventType;

@end

/**
 * Fetches the raw value of a @c StreamingRecognizeResponse's @c speechEventType property, even
 * if the value was not defined by the enum at the time the code was generated.
 **/
int32_t StreamingRecognizeResponse_SpeechEventType_RawValue(StreamingRecognizeResponse *message);
/**
 * Sets the raw value of an @c StreamingRecognizeResponse's @c speechEventType property, allowing
 * it to be set to a value that was not defined by the enum at the time the code
 * was generated.
 **/
void SetStreamingRecognizeResponse_SpeechEventType_RawValue(StreamingRecognizeResponse *message, int32_t value);

#pragma mark - StreamingRecognitionResult

typedef GPB_ENUM(StreamingRecognitionResult_FieldNumber) {
  StreamingRecognitionResult_FieldNumber_AlternativesArray = 1,
  StreamingRecognitionResult_FieldNumber_IsFinal = 2,
  StreamingRecognitionResult_FieldNumber_Stability = 3,
};

/**
 * A streaming speech recognition result corresponding to a portion of the audio
 * that is currently being processed.
 **/
@interface StreamingRecognitionResult : GPBMessage

/**
 * *Output-only* May contain one or more recognition hypotheses (up to the
 * maximum specified in `max_alternatives`).
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionAlternative*> *alternativesArray;
/** The number of items in @c alternativesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger alternativesArray_Count;

/**
 * *Output-only* If `false`, this `StreamingRecognitionResult` represents an
 * interim result that may change. If `true`, this is the final time the
 * speech service will return this particular `StreamingRecognitionResult`,
 * the recognizer will not return any further hypotheses for this portion of
 * the transcript and corresponding audio.
 **/
@property(nonatomic, readwrite) BOOL isFinal;

/**
 * *Output-only* An estimate of the likelihood that the recognizer will not
 * change its guess about this interim result. Values range from 0.0
 * (completely unstable) to 1.0 (completely stable).
 * This field is only provided for interim results (`is_final=false`).
 * The default of 0.0 is a sentinel value indicating `stability` was not set.
 **/
@property(nonatomic, readwrite) float stability;

@end

#pragma mark - SpeechRecognitionResult

typedef GPB_ENUM(SpeechRecognitionResult_FieldNumber) {
  SpeechRecognitionResult_FieldNumber_AlternativesArray = 1,
};

/**
 * A speech recognition result corresponding to a portion of the audio.
 **/
@interface SpeechRecognitionResult : GPBMessage

/**
 * *Output-only* May contain one or more recognition hypotheses (up to the
 * maximum specified in `max_alternatives`).
 **/
@property(nonatomic, readwrite, strong, null_resettable) NSMutableArray<SpeechRecognitionAlternative*> *alternativesArray;
/** The number of items in @c alternativesArray without causing the array to be created. */
@property(nonatomic, readonly) NSUInteger alternativesArray_Count;

@end

#pragma mark - SpeechRecognitionAlternative

typedef GPB_ENUM(SpeechRecognitionAlternative_FieldNumber) {
  SpeechRecognitionAlternative_FieldNumber_Transcript = 1,
  SpeechRecognitionAlternative_FieldNumber_Confidence = 2,
};

/**
 * Alternative hypotheses (a.k.a. n-best list).
 **/
@interface SpeechRecognitionAlternative : GPBMessage

/** *Output-only* Transcript text representing the words that the user spoke. */
@property(nonatomic, readwrite, copy, null_resettable) NSString *transcript;

/**
 * *Output-only* The confidence estimate between 0.0 and 1.0. A higher number
 * indicates an estimated greater likelihood that the recognized words are
 * correct. This field is typically provided only for the top hypothesis, and
 * only for `is_final=true` results. Clients should not rely on the
 * `confidence` field as it is not guaranteed to be accurate, or even set, in
 * any of the results.
 * The default of 0.0 is a sentinel value indicating `confidence` was not set.
 **/
@property(nonatomic, readwrite) float confidence;

@end

NS_ASSUME_NONNULL_END

CF_EXTERN_C_END

#pragma clang diagnostic pop

// @@protoc_insertion_point(global_scope)
