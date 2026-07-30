#include "complicated_seed.h"

#include "third-party/imgui/imgui.h"
#include "third-party/imgui/imgui_stdlib.h"

std::string g_complicated_seed_text;

ComplicatedSeedMenu::ComplicatedSeedMenu() {}

void ComplicatedSeedMenu::draw_window() {
  ImGui::Begin("Complicated Seed");
  ImGui::Text("Enter a seed:");
  ImGui::InputText("Seed", &g_complicated_seed_text, ImGuiInputTextFlags_CharsDecimal);
  if (ImGui::Button("Clear")) {
    g_complicated_seed_text.clear();
  }
  ImGui::End();
}