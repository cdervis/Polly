---
icon: material/television-guide
---

# Dear ImGui

Dear ImGui is integrated into Polly as a first-class component and is automatically available in the `Game` class.

You don't have to manage any ImGui objects. Just override the `#!cpp Game::onImGui()` method and use it directly:

```cpp
struct MyGame : Game
{
    Vec2 someVec2;

    void onImGui(ImGui imgui) override
    {
        imgui.beginWindow("My ImGui Window");
        imgui.text("Hello World!");

        if (imgui.button("Click here"))
        {
            logInfo("Button was clicked!");
        }

        if (imgui.slider("Some Vec2", someVec2, 0.0f, 5.0f))
        {
            logInfo("Slider changed to: {}", someVec2);
        }

        imgui.endWindow();
    }
};
```

Drawing of the ImGui elements is handled automatically by Polly at the right time.

For detailed instructions and documentation, please visit the [Dear ImGui website](https://github.com/ocornut/imgui).

!!! note
    More documentation will follow soon.
