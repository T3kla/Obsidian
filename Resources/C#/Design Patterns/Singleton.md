# Singleton

Object of which can only exist one unique instance.

-   **Problem**. Changing scenes break the execution of certain MonoBehaviour but it is needed from the start in many scenes.
-   **Solution**. Ensure unique instance and non deletion between scene changes.
-   **Benefit**. Can add the prefab to any scene knowing that it won't cause problems.
-   **Compromise**. Can be misused to handle references, but it shouldn't be.

```cs
using UnityEngine;

public abstract class Singleton<T> : MonoBehaviour where T : Component
{
    protected static T Instance { get; private set; }

    protected virtual void Awake()
    {
        if (Instance != null)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this as T;
    }
}

public abstract class SingletonPersistent<T> : MonoBehaviour where T : Component
{
    protected static T Instance { get; private set; }

    protected virtual void Awake()
    {
        if (Instance != null)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this as T;
        DontDestroyOnLoad(gameObject);
    }
}
```