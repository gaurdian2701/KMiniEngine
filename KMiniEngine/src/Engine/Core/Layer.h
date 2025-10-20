class Layer
{
public:
	Layer() = default;
	virtual void OnAttach() {}
	virtual void OnDetach() {}
	virtual void Update() {}
};