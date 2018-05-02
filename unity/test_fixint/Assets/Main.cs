using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using UnityEngine.UI;

public class Main : MonoBehaviour {


    public double test_sin(double val)
    {
        return Math.Sin(val);
    }

    int TEST_COUNT = 20;

    void myprintf(int i, double valf)
    {
        byte[] buf = BitConverter.GetBytes(valf);
        string hexStr = HexToString(buf);
        string txt = i.ToString() + ": " + hexStr;
        if (GameObject.Find("Canvas/Text").GetComponent<Text>().text !="") {
            txt = GameObject.Find("Canvas/Text").GetComponent<Text>().text + "\n" + txt;
        }
        GameObject.Find("Canvas/Text").GetComponent<Text>().text = txt;
    }

    string HexToString(byte[] bytes)
    {
        string hexString = "";
        for (int i = bytes.Length - 1; i >= 0; i--)
        {
            hexString += bytes[i].ToString("X2");
        }
        return hexString;
    }


    // Use this for initialization
    void Start () {
        double valf = 0.25f;
        myprintf(-1, valf);
        for (int i = 0; i < TEST_COUNT; i++)
        {
            valf = test_sin(valf);
            myprintf(i, valf);
        }
    }
	
	// Update is called once per frame
	void Update () {
		
	}
}
