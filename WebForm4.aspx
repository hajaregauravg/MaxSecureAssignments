<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm4.aspx.cs" Inherits="WebApplication1.WebForm4" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <h1>Hey There</h1>
        <table>
            <tr>
                <td>
                    Enter your username:
                </td>
                <td>
                    <asp:TextBox ID="username_TextBox" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td>
                    
                    <asp:Button ID="delete_Button" runat="server" Text="Delete" 
                        onclick="delete_Button_Click" />
                    
                </td>
            </tr>
           
        </table>
    </div>
    </form>
</body>
</html>
