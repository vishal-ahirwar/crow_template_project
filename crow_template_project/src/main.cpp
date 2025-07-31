#include <crow.h>
#include <crow/mustache.h>

int main() {
  crow::SimpleApp app;
  auto index_html = crow::mustache::load_text("index.html");
  CROW_ROUTE(app, "/<string>")(
      [](const std::string arg) { return "Hello there, " + arg; });

  CROW_ROUTE(app, "/")([&index_html]() { return index_html; });

  app.port(18080).concurrency(16).run();
}