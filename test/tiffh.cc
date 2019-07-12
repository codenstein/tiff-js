#include <nan.h>
#include <string.h>
#include <limits.h>
#include "../tiff.h"

using namespace v8;

#undef max

// req'd since size_t are 64-bit values on 64-bit Windows operating systems and
// v8 does not support 64-bit numbers.
int SizeTToInt(size_t data)
{
    if (data > std::numeric_limits<int>::max())
    {
        fprintf(stderr, "%s", "Invalid cast. size_t exceeds the numeric limit of int.\n");
        abort();
    }
    return static_cast<int>(data);
}

#define STR(x) #x

#define ADD_TYPE(types, type)                                                                      \
    {                                                                                              \
        v8::Local<v8::Object> _type = Nan::New<v8::Object>();                                      \
        _type->Set(Nan::New("size").ToLocalChecked(), Nan::New<Number>(SizeTToInt(sizeof(type)))); \
        types->Set(Nan::New(STR(type)).ToLocalChecked(), _type);                                   \
    }

#define ADD_OFFSET(structs, type, member)                                                                                       \
    {                                                                                                                           \
        v8::Local<v8::Object> _type = Nan::To<v8::Object>(structs->Get(Nan::New(STR(type)).ToLocalChecked())).ToLocalChecked(); \
        v8::Local<v8::Object> offsets = Nan::To<v8::Object>(_type->Get(Nan::New("offsets").ToLocalChecked())).ToLocalChecked(); \
        offsets->Set(Nan::New(STR(member)).ToLocalChecked(), Nan::New<Number>(SizeTToInt(offsetof(type, member))));             \
    }

#define ADD_STRUCT(structs, type)                                                                    \
    {                                                                                                \
        v8::Local<v8::Object> _struct = Nan::New<v8::Object>();                                      \
        _struct->Set(Nan::New("size").ToLocalChecked(), Nan::New<Number>(SizeTToInt(sizeof(type)))); \
        _struct->Set(Nan::New("offsets").ToLocalChecked(), Nan::New<v8::Object>());                  \
        structs->Set(Nan::New(STR(type)).ToLocalChecked(), _struct);                                 \
    }

void InitTypedefs(v8::Local<v8::Object> exports)
{
    v8::Local<v8::Object> typedefs = Nan::New<v8::Object>();

    v8::Local<v8::Object> types = Nan::New<v8::Object>();
    ADD_TYPE(types, int8);
    ADD_TYPE(types, uint8);

    ADD_TYPE(types, int16);
    ADD_TYPE(types, uint16);

    ADD_TYPE(types, int32);
    ADD_TYPE(types, uint32);

    ADD_TYPE(types, int64);
    ADD_TYPE(types, uint64);

    ADD_TYPE(types, uint16_vap);
    typedefs->Set(Nan::New("types").ToLocalChecked(), types);

    v8::Local<v8::Object> structs = Nan::New<v8::Object>();

    /*
 * TIFF header.
 */
    /* Fixed point structure type. */
    ADD_STRUCT(structs, TIFFHeaderCommon);
    ADD_OFFSET(structs, TIFFHeaderCommon, tiff_magic);
    ADD_OFFSET(structs, TIFFHeaderCommon, tiff_version);

    /* Defines a frame rectangle in const ICAP_UNITS coordinates. */
    ADD_STRUCT(structs, TIFFHeaderClassic);
    ADD_OFFSET(structs, TIFFHeaderClassic, tiff_magic);
    ADD_OFFSET(structs, TIFFHeaderClassic, tiff_version);
    ADD_OFFSET(structs, TIFFHeaderClassic, tiff_diroff);

    /* Defines the parameters used for channel-specific transformation. */
    ADD_STRUCT(structs, TIFFHeaderBig);
    ADD_OFFSET(structs, TIFFHeaderBig, tiff_magic);
    ADD_OFFSET(structs, TIFFHeaderBig, tiff_version);
    ADD_OFFSET(structs, TIFFHeaderBig, tiff_offsetsize);
    ADD_OFFSET(structs, TIFFHeaderBig, tiff_unused);
    ADD_OFFSET(structs, TIFFHeaderBig, tiff_diroff);

    typedefs->Set(Nan::New("structs").ToLocalChecked(), structs);

    exports->Set(Nan::New("typedefs").ToLocalChecked(), typedefs);
}

NAN_MODULE_INIT(Init)
{
    InitTypedefs(target);
}

NODE_MODULE(tiffh, Init);