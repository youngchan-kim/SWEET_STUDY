using System;
using System.Xml;
using System.Reflection;
using System.Collections.Generic;
using UnityEngine;

public class XML<T> where T : new()
{
    /// <summary>
    /// Resources �������� xml ������ ã�´�.
    /// </summary>
    public static List<T> Read(string name)
    {
        if (string.IsNullOrEmpty(name)) throw new ArgumentNullException("name");

        // name���� Ȯ���ڸ� ����.
        name = System.IO.Path.GetFileNameWithoutExtension(name);
        var xmlText = Resources.Load<TextAsset>(name);
        if (!xmlText) throw new Exception(string.Format("Not Find TextAsset : {0}", name));

        var xmlDoc = new XmlDocument();
        xmlDoc.LoadXml(xmlText.text); // text������ xml ������ ���·� ��ȯ.
        var root = xmlDoc.DocumentElement;
        List<T> dataList = new List<T>();
        foreach (XmlElement node in root.ChildNodes)
        {
            // Reflection�� �̿��Ͽ�,
            T data = new T();
            var type = data.GetType();   //  T�� ��������(Type)��,
            var fields = type.GetFields(); // ����(Field)���� ã�´�.
            foreach (var field in fields)
            {
                // xml���� ���� ��� ���� Attribute�� ã�� ���� ���� �´�.
                var strValue = node.GetAttribute(field.Name);
                if (null != strValue) // �� ���ڿ��� ���� �� ���� ������ null Ȯ�θ� �Ѵ�.
                {
                    object value = strValue;
                    if (int.TryParse(strValue, out int i)) value = i;
                    else if (float.TryParse(strValue, out float f)) value = f;
                    else if (double.TryParse(strValue, out double d)) value = d;

                    // �ش� field�� �´� ������ �����͸� �Է�.
                    field.SetValue(data, value);
                }
            }
            // List�� ������ �߰�.
            dataList.Add(data);
        }

        return dataList;
    }

    /// <summary>
    /// Assets/Resources/...������ name���� xml ���� ����.
    /// </summary>
    public static void Write(string name, List<T> dataList)
    {
        if (string.IsNullOrEmpty(name)) throw new ArgumentNullException("name");
        if(null == dataList || 1 > dataList.Count) throw new ArgumentNullException("dataList");

        var xmlDoc = new XmlDocument();
        var root = xmlDoc.CreateElement("root"); // xml �������� root ����.
        xmlDoc.AppendChild(root);                    // xml �����Ϳ� root �߰�.

        var type = typeof(T); // Reflection�� �̿��Ͽ� �����͸� ���ϱ� ���� Type�� ���Ѵ�.
        foreach (var data in dataList)
        {
            // T�� ���������� �̸����� �ϴ� Element�� ����.
            var node = xmlDoc.CreateElement(type.Name);

            var fields = type.GetFields();
            foreach (var field in fields)
            {
                // �������� �̸����� �ϴ� Attribute�� ����.
                var attr = xmlDoc.CreateAttribute(field.Name);
                // ������ ���ϰ� �ִ� ���� ���ڿ����·� ��ȯ�Ͽ� Attribute�� ����.
                attr.Value = field.GetValue(data).ToString();
                // Element�� Attribute �߰�.
                node.Attributes.Append(attr);
            }
            // root�� Element �߰�.
            root.AppendChild(node);
        }

        // Ȯ���ڰ� ������ ".xml"�� ����, ���ٸ� �߰�.
        name = System.IO.Path.ChangeExtension(name, ".xml");
        // Application.dataPath : Assets ���������� ���.
        // .../Assets/Resources/name.xml
        var path = string.Format(@"{0}/Resources/{1}", Application.dataPath, name);
        // ���ϸ��� ������ ������ ���������� ��θ��� ���Ѵ�.
        var directoryPath = System.IO.Path.GetDirectoryName(path);
        // Assets ������ �ٷ� ������ Resources ������ ���ٸ� ����.
        if (!System.IO.Directory.Exists(directoryPath)) System.IO.Directory.CreateDirectory(directoryPath);

        // �ش� ������Ʈ�� Resources/...������ xml ���� ����.
        xmlDoc.Save(path);
    }
}
