#include "complicated_seed.h"
#include "third-party/imgui/imgui.h"
#include "third-party/imgui/imgui_stdlib.h"

#include <fstream>
#include <sstream>

std::string g_complicated_seed_text;

namespace {
const char* kSeedFilePath = "complicated_seed.txt";
}

ComplicatedSeedMenu::ComplicatedSeedMenu() {
  std::ifstream in(kSeedFilePath);
  if (in) {
    std::stringstream ss;
    ss << in.rdbuf();
    g_complicated_seed_text = ss.str();
  }
}

void ComplicatedSeedMenu::draw_window() {
  ImGui::Begin("Complicated Seed");
  // ImGui::Text("Enter a seed:");
  ImGui::InputText("Seed", &g_complicated_seed_text, ImGuiInputTextFlags_CharsDecimal);

  if (ImGui::IsItemDeactivatedAfterEdit()) {
    std::ofstream out(kSeedFilePath);
    out << g_complicated_seed_text;
  }

  if (ImGui::Button("Clear")) {
    g_complicated_seed_text.clear();
    std::ofstream out(kSeedFilePath);
  }

  ImGui::End();
}