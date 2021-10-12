```cs
using System.Collections.Generic;
using TLogger;
using UnityEngine;

namespace TPooling
{
    public interface IPoolable
    {
        string pTag { get; set; }
        GameObject gameObject { get; }
        Transform transform { get; }
        void Enabled();
        void Disable();
    }

    public static class ObjPooler
    {
        private static readonly Dictionary<string, (IPoolable prefab, Queue<IPoolable> pool)> Pools
            = new Dictionary<string, (IPoolable prefab, Queue<IPoolable> pool)>(10);

        private static IPoolable CreateOne(IPoolable prefab)
            => GameObject.Instantiate(prefab.transform, Vector3.zero, Quaternion.identity).GetComponent<IPoolable>();

        public static void CreatePool(string tag, IPoolable prefab, int size = 1)
        {
            if (size is 0) return;
            if (prefab is null) { Log.Error("Received null prefab"); return; }
            if (Pools.ContainsKey(tag)) { Log.Error($"Tag '{tag}' is already being used"); return; }

            Pools[tag] = (prefab, new Queue<IPoolable>(size));

            for (int i = 0; i < size; i++)
            {
                var entity = CreateOne(prefab);
                entity.pTag = tag;
                entity.gameObject.SetActive(false);
                Pools[tag].pool.Enqueue(entity);
            }
        }

        public static IPoolable Instantiate(in string tag, Vector3 position, Quaternion rotation, Transform parent = null)
        {
            if (!Pools.ContainsKey(tag)) { Log.Error($"Tag '{tag}' doesn't exists"); return null; }

            var entity = Pools[tag].pool.Count > 0 ? Pools[tag].pool.Dequeue() : CreateOne(Pools[tag].prefab);

            entity.pTag = tag;
            entity.transform.position = position;
            entity.transform.rotation = rotation;
            entity.transform.SetParent(parent);
            entity.gameObject.SetActive(true);
            entity.Enabled();
            return entity;
        }

        public static void Disable(IPoolable entity)
        {
            entity.gameObject.SetActive(false);
            var tag = entity.pTag;

            if (!Pools.ContainsKey(tag))
            {
                GameObject.Destroy(entity.gameObject);
                return;
            }

            Pools[tag].pool.Enqueue(entity);
        }

        public static void Clear(in string tag)
        {
            if (!Pools.ContainsKey(tag)) { Log.Error($"Tag '{tag}' doesn't exists"); return; }

            foreach (var entity in Pools[tag].pool)
            {
                entity.gameObject.SetActive(false);
                GameObject.Destroy(entity.gameObject);
            }

            Pools.Remove(tag);
        }

        public static void ClearAll()
        {
            foreach (var pair in Pools)
                foreach (var entity in pair.Value.pool)
                    GameObject.Destroy(entity.gameObject);

            Pools.Clear();
        }
    }
}
```