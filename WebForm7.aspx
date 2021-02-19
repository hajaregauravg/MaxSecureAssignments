<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm7.aspx.cs" Inherits="WebApplication1.WebForm7" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table border="0">
            <tr>
                <td>
                    <h1>Hey There</h1><br />
                </td>
            </tr>
            <tr>
                <td>
                    <h3>Enter Your Log-in ID Here:</h3>
                </td>
                <td>
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br/>
                </td>
            </tr>
            <tr>
                <td>
                    <h3>Enter new Log-in ID Here:</h3>
                </td>
                <td>
                    <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td colspan="2">
                    <asp:Button ID="Button1" runat="server" Text="Click to Update Login_ID" Height="36px" 
                        Width="327px" onclick="Button1_Click" />
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
