#ifndef __GTHREE_SHADER_MATERIAL_H__
#define __GTHREE_SHADER_MATERIAL_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gthree/gthreemeshmaterial.h>

G_BEGIN_DECLS


#define GTHREE_TYPE_SHADER_MATERIAL      (gthree_shader_material_get_type ())
#define GTHREE_SHADER_MATERIAL(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                                     GTHREE_TYPE_SHADER_MATERIAL, \
                                                                     GthreeShaderMaterial))
#define GTHREE_IS_SHADER_MATERIAL(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst), \
                                                                     GTHREE_TYPE_SHADER_MATERIAL))

struct _GthreeShaderMaterial {
  GthreeMeshMaterial parent;
};

typedef struct {
  GthreeMeshMaterialClass parent_class;

} GthreeShaderMaterialClass;

G_DEFINE_AUTOPTR_CLEANUP_FUNC (GthreeShaderMaterial, g_object_unref)

GTHREE_API
GType gthree_shader_material_get_type (void) G_GNUC_CONST;

GTHREE_API
GthreeShaderMaterial *gthree_shader_material_new (GthreeShader *shader);

GTHREE_API
GthreeShadingType gthree_shader_material_get_shading_type  (GthreeShaderMaterial *shader);
GTHREE_API
void              gthree_shader_material_set_shading_type  (GthreeShaderMaterial *shader,
                                                            GthreeShadingType     shading_type);
GTHREE_API
void              gthree_shader_material_set_vertex_colors (GthreeShaderMaterial *shader,
                                                            gboolean              vertex_color);
GTHREE_API
gboolean          gthree_shader_material_get_vertex_colors (GthreeShaderMaterial *shader);
GTHREE_API
void              gthree_shader_material_set_use_lights    (GthreeShaderMaterial *shader,
                                                            gboolean              use_lights);
GTHREE_API
gboolean          gthree_shader_material_get_use_lights    (GthreeShaderMaterial *shader);

G_END_DECLS

#endif /* __GTHREE_SHADER_MATERIAL_H__ */
