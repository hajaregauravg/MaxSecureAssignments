using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Diagnostics;

namespace WebApplication1
{
    public partial class WebForm3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string sp_update = "";
            SqlConnection con = new SqlConnection(@"Data Source=TEST\MSSQLSERVER1; Initial Catalog= My_database; AttachDbFilename=C:\Program Files\Microsoft SQL Server\MSSQL14.MSSQLSERVER1\MSSQL\DATA\My_database.mdf;Integrated Security=True");
            sp_update = "UPDATE creds SET Password =(@new_password) WHERE ID = (SELECT ID FROM creds WHERE Login_ID = (@Login_ID))";
            SqlCommand cmd = new SqlCommand(sp_update, con);
            cmd.Parameters.AddWithValue("@Login_ID", user_name_TextBox.Text);
            cmd.Parameters.AddWithValue("@new_password", new_password_TextBox.Text);
            con.Open();
            int i = cmd.ExecuteNonQuery();

            con.Close();
            if (i != 0)
            {
                Debug.WriteLine("Data Updated");
            }

            Server.Transfer("WebForm1.aspx");
        }
    }
}