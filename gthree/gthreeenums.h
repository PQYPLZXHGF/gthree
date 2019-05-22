#ifndef __GTHREE_ENUM_H__
#define __GTHREE_ENUM_H__

G_BEGIN_DECLS

typedef enum {
  GTHREE_BLEND_NO,
  GTHREE_BLEND_NORMAL,
  GTHREE_BLEND_ADDITIVE,
  GTHREE_BLEND_SUBTRACTIVE,
  GTHREE_BLEND_MULTIPLY,
  GTHREE_BLEND_CUSTOM
} GthreeBlendMode;

typedef enum {
  GTHREE_SIDE_FRONT,
  GTHREE_SIDE_BACK,
  GTHREE_SIDE_DOUBLE
} GthreeSide;

typedef enum {
  GTHREE_CULL_FACE_NONE,
  GTHREE_CULL_FACE_FRONT,
  GTHREE_CULL_FACE_BACK,
  GTHREE_CULL_FACE_FRONT_BACK
} GthreeCullFace;

typedef enum {
  GTHREE_FRONT_FACE_DIRECTION_CW,
  GTHREE_FRONT_FACE_DIRECTION_CCW
} GthreeFrontFaceDirection;

typedef enum {
  GTHREE_SHADING_NONE,
  GTHREE_SHADING_FLAT,
  GTHREE_SHADING_SMOOTH,
} GthreeShadingType;

typedef enum {
  GTHREE_COLOR_NONE,
  GTHREE_COLOR_FACE,
  GTHREE_COLOR_VERTEX,
} GthreeColorType;

typedef enum {
  GTHREE_PRECISION_LOW,
  GTHREE_PRECISION_MEDIUM,
  GTHREE_PRECISION_HIGH,
} GthreePrecision;

typedef enum {
  GTHREE_OPERATION_MULTIPLY,
  GTHREE_OPERATION_MIX,
  GTHREE_OPERATION_ADD,
} GthreeOperation;

typedef enum {
  GTHREE_WRAPPING_REPEAT,
  GTHREE_WRAPPING_CLAMP,
  GTHREE_WRAPPING_MIRRORED,
} GthreeWrapping;

typedef enum {
  GTHREE_FILTER_NEAREST,
  GTHREE_FILTER_NEAREST_MIPMAP_NEAREST,
  GTHREE_FILTER_NEAREST_MIPMAP_LINEAR,
  GTHREE_FILTER_LINEAR,
  GTHREE_FILTER_LINEAR_MIPMAP_NEAREST,
  GTHREE_FILTER_LINEAR_MIPMAP_LINEAR,
} GthreeFilter;

typedef enum {
  GTHREE_MAPPING_UV,
  GTHREE_MAPPING_CUBE_REFLECTION,
  GTHREE_MAPPING_CUBE_REFRACTION,
  GTHREE_MAPPING_SPHERICAL_REFLECTION,
  GTHREE_MAPPING_SPHERICAL_REFRACTION,
} GthreeMapping;

typedef enum {
  GTHREE_ATTRIBUTE_TYPE_DOUBLE,
  GTHREE_ATTRIBUTE_TYPE_FLOAT,
  GTHREE_ATTRIBUTE_TYPE_UINT32,
  GTHREE_ATTRIBUTE_TYPE_INT32,
  GTHREE_ATTRIBUTE_TYPE_UINT16,
  GTHREE_ATTRIBUTE_TYPE_INT16,
  GTHREE_ATTRIBUTE_TYPE_UINT8,
  GTHREE_ATTRIBUTE_TYPE_INT8,
} GthreeAttributeType;

G_END_DECLS

#endif /* __GTHREE_ENUM_H__ */
