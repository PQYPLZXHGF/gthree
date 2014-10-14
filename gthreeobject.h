#ifndef __GTHREE_OBJECT_H__
#define __GTHREE_OBJECT_H__

#include <gtk/gtk.h>
#include <graphene.h>

G_BEGIN_DECLS

#define GTHREE_PRIVATE_FIELD(x)        x

#define GTHREE_TYPE_OBJECT      (gthree_object_get_type ())
#define GTHREE_OBJECT(inst)     (G_TYPE_CHECK_INSTANCE_CAST ((inst), \
                                                             GTHREE_TYPE_OBJECT, \
                                                             GthreeObject))
#define GTHREE_IS_OBJECT(inst)  (G_TYPE_CHECK_INSTANCE_TYPE ((inst),    \
                                                             GTHREE_TYPE_OBJECT))

typedef struct {
  GInitiallyUnowned parent;
} GthreeObject;

typedef struct {
  GInitiallyUnownedClass parent_class;

  void (* parent_set)           (GthreeObject          *object,
                                 GthreeObject          *old_parent);

  void (* destroy)              (GthreeObject          *object);

} GthreeObjectClass;

GType gthree_object_get_type (void) G_GNUC_CONST;

GthreeObject *gthree_object_new ();

void gthree_object_get_matrix_world (GthreeObject *object,
                                     graphene_matrix_t *res);

void          gthree_object_set_matrix_auto_update (GthreeObject *object,
                                                    gboolean auto_update);
void          gthree_object_update_matrix_world   (GthreeObject *object,
                                                   gboolean force);
void          gthree_object_update_matrix         (GthreeObject *object);
void          gthree_object_look_at              (GthreeObject *object,
                                                  graphene_vec3_t *vector);

void          gthree_object_add_child            (GthreeObject *object,
                                                  GthreeObject *child);
void          gthree_object_remove_child         (GthreeObject *object,
                                                  GthreeObject *child);
void          gthree_object_destroy              (GthreeObject *object);
GthreeObject *gthree_object_get_parent           (GthreeObject *object);
GthreeObject *gthree_object_get_first_child      (GthreeObject *object);
GthreeObject *gthree_object_get_last_child       (GthreeObject *object);
GthreeObject *gthree_object_get_next_sibling     (GthreeObject *object);
GthreeObject *gthree_object_get_previous_sibling (GthreeObject *object);
void          gthree_object_destroy_all_children (GthreeObject *object);

typedef struct _GthreeObjectIter GthreeObjectIter;

struct _GthreeObjectIter
{
  /*< private >*/
  gpointer GTHREE_PRIVATE_FIELD (dummy1);
  gpointer GTHREE_PRIVATE_FIELD (dummy2);
  gpointer GTHREE_PRIVATE_FIELD (dummy3);
  gint     GTHREE_PRIVATE_FIELD (dummy4);
  gpointer GTHREE_PRIVATE_FIELD (dummy5);
};

void     gthree_object_iter_init     (GthreeObjectIter        *iter,
                                      GthreeObject            *root);
gboolean gthree_object_iter_is_valid (const GthreeObjectIter  *iter);
gboolean gthree_object_iter_next     (GthreeObjectIter        *iter,
                                      GthreeObject           **child);
gboolean gthree_object_iter_prev     (GthreeObjectIter        *iter,
                                      GthreeObject           **child);
void     gthree_object_iter_remove   (GthreeObjectIter        *iter);
void     gthree_object_iter_destroy  (GthreeObjectIter        *iter);

G_END_DECLS

#endif /* __GTHREE_OBJECT_H__ */
