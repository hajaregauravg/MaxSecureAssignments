<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm2.aspx.cs" Inherits="WebApplication1.WebForm2" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table>
            <tr>
                <td>
                    <h1>Hey Friend!!</h1>
                </td>
            </tr>

            <tr>
                <td>
                    Enter the old username you want to change:
                </td>
                <td>
                    <asp:TextBox ID="old_user_name_TextBox" runat="server"></asp:TextBox><br/>
                </td>
            </tr>
            <tr>
                <td>
                    Enter the new username:
                </td>
                <td>
                    <asp:TextBox ID="new_user_name_TextBox" runat="server"></asp:TextBox><br/>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="Button1" runat="server" Text="Click to change username" onclick="Button1_Click" />
                </td>
            </tr>
        </table>
    </div>

    </form>
</body>
</html>
