#ifndef __GTHREE_PROPERTY_MIXER_H__
#define __GTHREE_PROPERTY_MIXER_H__

#if !defined (__GTHREE_H_INSIDE__) && !defined (GTHREE_COMPILATION)
#error "Only <gthree/gthree.h> can be included directly."
#endif

#include <gio/gio.h>
#include <gthree/gthreetypes.h>
#include <gthree/gthreeenums.h>
#include <gthree/gthreeobject.h>
#include "gthreepropertybindingprivate.h"

G_BEGIN_DECLS

#define GTHREE_TYPE_PROPERTY_MIXER      (gthree_property_mixer_get_type ())
#define GTHREE_PROPERTY_MIXER(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst),  \
                                                  GTHREE_TYPE_PROPERTY_MIXER, \
                                                  GthreePropertyMixer))
#define GTHREE_PROPERTY_MIXER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GTHREE_TYPE_PROPERTY_MIXER, GthreePropertyMixerClass))
#define GTHREE_IS_PROPERTY_MIXER(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst),  \
                                                  GTHREE_TYPE_PROPERTY_MIXER))
#define GTHREE_PROPERTY_MIXER_GET_CLASS(inst) (G_TYPE_INSTANCE_GET_CLASS ((inst), GTHREE_TYPE_PROPERTY_MIXER, GthreePropertyMixerClass))


typedef struct  {
  GObject parent;

  /* Used by mixer */
  int use_count;
  int reference_count;
  int cache_index;
} GthreePropertyMixer;

typedef struct {
  GObjectClass parent_class;
} GthreePropertyMixerClass;


G_DEFINE_AUTOPTR_CLEANUP_FUNC (GthreePropertyMixer, g_object_unref)

GType gthree_property_mixer_get_type (void) G_GNUC_CONST;

GthreePropertyMixer *gthree_property_mixer_new (GthreePropertyBinding *binding,
                                                GthreeValueType        value_type,
                                                int                    value_size);


GthreePropertyBinding *gthree_property_mixer_get_binding            (GthreePropertyMixer *mixer);
void                   gthree_property_mixer_accumulate             (GthreePropertyMixer *mixer,
                                                                     GthreeAttributeArray *values,
                                                                     int                  accu_index,
                                                                     float                weight);
void                   gthree_property_mixer_apply                  (GthreePropertyMixer *mixer,
                                                                     int                  accu_index);
void                   gthree_property_mixer_save_original_state    (GthreePropertyMixer *mixer);
void                   gthree_property_mixer_restore_original_state (GthreePropertyMixer *mixer);


G_END_DECLS

#endif /* __GTHREE_PROPERTY_MIXER_H__ */
