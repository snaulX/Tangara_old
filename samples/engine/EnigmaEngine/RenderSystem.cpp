#include "AlphaEngine/ISystem.hpp"
#include "Tangara.hpp"

namespace EnigmaEngine
{
    class RenderSystem : AlphaEngine::ISystem {
    public:
        static RenderSystem* GetInstance() { return _instance; }

        RenderSystem() {
            if (_instance) {
                // don't create object
            }
            else {
                _instance = this;
            }
        }

        void Start() {
            // prepare to render
        }

    private:
        static RenderSystem *_instance;
    };

    TANGARA_SINGLETON(RenderSystem)
}