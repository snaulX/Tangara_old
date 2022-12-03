using EnigmaEngine;

namespace EnigmaLabs;

class ModelEntity : Entity
{
    public Model Model { get; set; }

    public override void Update()
    {
        Render.Draw(Model);
    }
}