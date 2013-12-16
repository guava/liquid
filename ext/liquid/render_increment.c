#include <render_increment.h>

/*
  value = context.environments.first[@variable] ||= 0
  context.environments.first[@variable] = value + 1
  value.to_s
*/
static VALUE cl_render(const VALUE self, const VALUE rb_context) {
  int final_value;

  VALUE rb_environments = rb_funcall(rb_context, rb_intern("environments"), 0);
  VALUE rb_first_env = rb_funcall(rb_environments, rb_intern("first"), 0);

  VALUE variable_name = rb_iv_get(self, "@variable");
  VALUE variable_value = rb_hash_aref(rb_first_env, variable_name);

  if(variable_value == Qnil) {
    final_value = 0;
  } else {
    final_value = FIX2INT(variable_value);
  }

  rb_hash_aset(rb_first_env, variable_name, INT2FIX(final_value + 1));

  return INT2FIX(final_value);
}

void init_render_increment() {
  VALUE liquid_module = rb_define_module("Liquid");
  VALUE rb_tagObject = rb_define_class_under(liquid_module, "Tag", rb_cObject);
  VALUE renderer_liquid = rb_define_class_under(liquid_module, "Cincrement", rb_tagObject);

  rb_define_method(renderer_liquid, "render", cl_render, 1);
}
