#include <ruby.h>

static VALUE cliquid;

static VALUE cl_render(const VALUE self) {
  return rb_str_new2("Hello Ruby from C!\n");
}

void Init_cliquid() {
  cliquid = rb_define_class("CLiquid", rb_cObject);

  rb_define_method(cliquid, "render", cl_render, 0);
}
